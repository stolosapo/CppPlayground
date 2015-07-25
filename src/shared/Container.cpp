#include <iostream>
#include <vector>
#include "Container.h"
#include "../log/LogServiceFactory.h"

using namespace std;

/*******************************
*
*		CONSTRUCTORS
*
********************************/

Container::Container(int id, string name, string title, const int size) : MenuItem()
{
	this->setId(id);
	this->setName(name);
	this->setTitle(title);
	this->setEnable(true);

	this->exitCode = DEFAULT_EXIT_CODE;
	this->useOptions = true;
	this->question = "Give option: ";

	this->size = size;
	this->menuItems = new MenuItem *[size];

	logSrv = LogServiceFactory::create();
}

Container::~Container()
{
	this->logSrv = NULL;
	delete[] this->menuItems;
}



/*******************************
*
*		GETTERS SETTERS
*
********************************/

int Container::getSize()
{
	return this->size;
}

string Container::getQuestion()
{
	return this->question;
}

int Container::getSelection()
{
	return this->selection;
}

int Container::getExitCode()
{
	return this->exitCode;
}

bool Container::getUseOptions()
{
	return this->useOptions;
}


void Container::setUseOptions(bool useOptions)
{
	this->useOptions = useOptions;
}

void Container::setQuestion(string question)
{
	this->question = question;
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

void Container::addMenuItem(int index, MenuItem *menuItem)
{
	this->menuItems[index] = menuItem;
}

MenuItem *Container::findMenuItem()
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
	
	return this->findMenuItem();
}

int Container::promptQuestion()
{
	logSrv->print(question);
	this->selection = logSrv->inInt();

	return this->selection;
}

void Container::showOptions() 
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
				logSrv->outString(current->getName());
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

void Container::action()
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
			selectedItem->action();
		}
		else
		{
			break;
		}
	}
}


string Container::identify()
{
	string message = this->getTitle() + "\n" +
	"####################################" + "\n\n" +
	this->getDescription();

	return message;
}
