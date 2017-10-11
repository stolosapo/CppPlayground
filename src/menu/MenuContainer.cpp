#include <iostream>
#include <vector>
#include "MenuContainer.h"
#include "../log/LogServiceFactory.h"

#include "../lib/di/GlobalAppContext.h"

#include "../lib/exception/domain/DomainException.h"

using namespace std;

/*******************************
*
*		CONSTRUCTORS
*
********************************/

MenuContainer::MenuContainer(int id, string name, string title, const int size) : MenuItem()
{
	this->setId(id);
	this->setName(name);
	this->setTitle(title);
	this->setEnable(true);

	this->exitCode = DEFAULT_EXIT_CODE;
	this->useOptions = true;
	this->question = "Give option: ";
	this->continueQuestion = false;

	this->size = size;
	this->menuItems = new MenuItem *[size];

	logSrv = inject<ILogService>("logService");
}

MenuContainer::~MenuContainer()
{
	this->logSrv = NULL;
	delete[] this->menuItems;
}



/*******************************
*
*		GETTERS SETTERS
*
********************************/

int MenuContainer::getSize()
{
	return this->size;
}

string MenuContainer::getQuestion()
{
	return this->question;
}

int MenuContainer::getSelection()
{
	return this->selection;
}

int MenuContainer::getExitCode()
{
	return this->exitCode;
}

bool MenuContainer::getUseOptions()
{
	return this->useOptions;
}

bool MenuContainer::getContinueQuestion()
{
	return this->continueQuestion;
}


void MenuContainer::setUseOptions(bool useOptions)
{
	this->useOptions = useOptions;
}

void MenuContainer::setQuestion(string question)
{
	this->question = question;
}

void MenuContainer::setContinueQuestion(bool continueQuestion)
{
	this->continueQuestion = continueQuestion;
}


/*******************************
*
*		PRIVATE METHODS
*
********************************/





/*******************************
*
*		PROTECTED METHODS
*
********************************/

void MenuContainer::addMenuItem(int index, MenuItem *menuItem)
{
	this->menuItems[index] = menuItem;
}

int MenuContainer::getMaxDisplaySize()
{
	int max = 0;
	int curSize = 0;

	MenuItem *current;

	for (int i = 0; i < this->size; ++i)
	{
		if (this->menuItems[i] != NULL)
		{
			current = this->menuItems[i];
			curSize = current->getTitle().length();

			if (curSize > max)
			{
				max = curSize;
			}
		}
	}

	return max;
}

MenuItem *MenuContainer::findMenuItem()
{
	if (this->selection == this->exitCode)
		return NULL;

	MenuItem *current;

	for (int i = 0; i < this->size; ++i)
	{
		if (this->menuItems[i] != NULL)
		{
			current = this->menuItems[i];
			if (current->getId() == this->selection)
			{
				return current;
			}
		}
	}

	logSrv->outString("No such item exists!!!\n\n");
	logSrv->outString("Choose again: ");

	this->selection = logSrv->inInt();

	/* Guard for unexpected input */
	if (this->selection < 0)
	{
		logSrv->fatal("Fatal selection");

		this->selection = this->exitCode;
	}

	return this->findMenuItem();
}

int MenuContainer::promptQuestion()
{
	logSrv->print(question);
	this->selection = logSrv->inInt();

	return this->selection;
}

bool MenuContainer::promptContinueQuestion()
{
	logSrv->print("Choose other option? (y/n): ");
	string cont = logSrv->inString();

	if (cont == "y" || cont == "Y")
	{
		return true;
	}

	return false;
}

void MenuContainer::showOptions()
{
	this->fillOptions();

	if (this->useOptions && menuItems != NULL)
	{

		logSrv->print("\n");
		logSrv->outInt(this->exitCode);
		logSrv->print(". Exit");
		logSrv->print("\n\n");

		for (int i = 0; i < this->size; ++i)
		{
			if (this->menuItems[i] != NULL)
			{
				MenuItem *current = this->menuItems[i];
				logSrv->outInt(current->getId());
				logSrv->outString(". ");
				logSrv->outString(current->getTitle());
				logSrv->outString("\n");
			}
		}

		logSrv->outString("\n");
	}
}



/*******************************
*
*		PUBLIC METHODS
*
********************************/

void MenuContainer::action()
{
	try
	{
		while(1)
		{
			logSrv->clearScreen();

			logSrv->outString(this->identify());

			this->showOptions();

			this->promptQuestion();

			MenuItem *selectedItem = this->findMenuItem();
			if (selectedItem != NULL)
			{
				logSrv->clearScreen();
				logSrv->outString(selectedItem->identify());
				selectedItem->action();

				if (this->continueQuestion)
				{
					bool cont = this->promptContinueQuestion();
					if (!cont)
					{
						break;
					}
				}

			}
			else
			{
				break;
			}
		}
	}
	catch (DomainException& e)
	{
		logSrv->error(e.what());
	}
	catch (exception& e)
	{
		throw e;
	}
}


string MenuContainer::identify()
{
	string header = this->getHeader();

	if (header == "")
	{
		header = this->getTitle();
	}

	string message = header + "\n" +
	"####################################" + "\n\n" +
	this->getDescription();

	return message;
}
