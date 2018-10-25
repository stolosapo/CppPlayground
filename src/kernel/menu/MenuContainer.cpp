#include <iostream>
#include <vector>
#include "MenuContainer.h"
#include "../log/LogServiceFactory.h"

#include "../di/GlobalAppContext.h"

#include "../utils/StringHelper.h"
#include "../converter/Convert.h"

#include "../exception/domain/DomainException.h"
#include "../exception/ExceptionMapper.h"

using namespace std;

/*******************************
*
*		CONSTRUCTORS
*
********************************/

MenuContainer::MenuContainer(int id, string name, string title) : MenuItem()
{
	this->setId(id);
	this->setName(name);
	this->setTitle(title);
	this->setEnable(true);

	this->exitCode = DEFAULT_EXIT_CODE;
	this->useOptions = true;
	this->question = "Give option: ";
	this->continueQuestion = false;

	logSrv = inject<ILogService>("logService");
	sigSrv = inject<SignalService>("signalService");
}

MenuContainer::~MenuContainer()
{
    clear();
}



/*******************************
*
*		GETTERS SETTERS
*
********************************/

int MenuContainer::getSize()
{
	return items.size();
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
    items.push_back(menuItem);
}

void MenuContainer::clear()
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items.at(i) == NULL)
        {
            continue;
        }

        delete items.at(i);
    }

    vector<MenuItem*>().swap(items);
}

int MenuContainer::getMaxDisplaySize()
{
	int max = 0;
	int curSize = 0;

	MenuItem *current;

	for (int i = 0; i < items.size(); ++i)
	{
		if (items.at(i) != NULL)
		{
			current = items.at(i);
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
    {
		return NULL;
    }

	MenuItem *current;

	for (int i = 0; i < items.size(); ++i)
	{
		if (items.at(i) != NULL)
		{
			current = items.at(i);
			if (current->getId() == this->selection)
			{
				return current;
			}
		}
	}

	this->selection = this->exitCode;
	logSrv->outString("No such item exists!!!\n\n");
	logSrv->outString("Choose again: ");

	this->selection = logSrv->inInt();

	/* Check for Interruption */
	if (sigSrv->gotSigIntAndReset())
	{
		cin.clear();
		cin.ignore();

		this->selection = this->exitCode;
	}

	/* Guard for unexpected input */
	if (this->selection < 0)
	{
		cin.clear();
		cin.ignore();

		logSrv->fatal("Fatal selection");

		this->selection = this->exitCode;
	}

	return this->findMenuItem();
}

MenuItem* MenuContainer::findMenuItemByName(string name)
{
    if (items.empty())
    {
        fillOptions();
    }

    for (int i = 0; i < items.size(); ++i)
	{
        MenuItem* item = items.at(i);
        MenuContainer* menu = dynamic_cast<MenuContainer*>(item);

        /* If found return it */
        if (item->getName() == name)
        {
            return item;
        }

        /* If is NOT ManuContainer keep searching */
        if (menu == NULL)
        {
            continue;
        }

        /* If IS MenuContainer search inside menu */
        MenuItem* found = menu->findMenuItemByName(name);

        /* If found return it */
        if (found != NULL)
        {
            return found;
        }

        /* If not found continue searching */
	}

    return NULL;
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
    if (items.empty())
    {
        fillOptions();
    }

	if (this->useOptions)
	{

		logSrv->print("\n");
		logSrv->outInt(this->exitCode);
		logSrv->print(". Exit");
		logSrv->print("\n\n");

		for (int i = 0; i < items.size(); ++i)
		{
			if (items.at(i) != NULL)
			{
				MenuItem *current = items.at(i);
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
			if (selectedItem == NULL)
			{
				break;
			}

			logSrv->clearScreen();
			logSrv->outString(selectedItem->identify());

			selectedItem->check();
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
	}
	catch (DomainException& e)
	{
		logSrv->error(handle(e));
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

void MenuContainer::tree(int depth)
{
    if (items.empty())
    {
        fillOptions();
    }

    for (int i = 0; i < items.size(); ++i)
    {
        MenuItem* item = items.at(i);
        MenuContainer* menu = dynamic_cast<MenuContainer*>(item);

        string padding = StringHelper::pad(" ", depth);
        string type = menu == NULL ? "[ITEM]" : "[MENU]";

        string itemStr = "* " + type + " " ;
        itemStr += "id: " + Convert<int>::NumberToString(item->getId());
        itemStr += ", name: " + item->getName();
        itemStr += ", title: " + item->getTitle();
        // itemStr += ", description: " + item->getDescription();

        cout << padding << itemStr << endl;

        /* If is Menu */
        if (menu != NULL)
        {
            menu->tree(depth + 2);
        }
    }
}

void MenuContainer::tree()
{
    tree(0);
}
