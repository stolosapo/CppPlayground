#include <iostream>
#include <string>
#include "MenuItem.h"

using namespace std;

MenuItem::MenuItem()
{

}

MenuItem::~MenuItem()
{
	
}

int MenuItem::getId()
{
	return this->id;
}

string MenuItem::getName()
{
	return this->name;
}

string MenuItem::getTitle()
{
	return this->title;
}

string MenuItem::getDescription()
{
	return this->description;
}

bool MenuItem::getEnable()
{
	return this->enable;
}


void MenuItem::setId(int id)
{
	this->id = id;
}

void MenuItem::setName(string name)
{
	this->name = name;
}

void MenuItem::setTitle(string title)
{
	this->title = title;
}

void MenuItem::setDescription(string description)
{
	this->description = description;
}


void MenuItem::setEnable(bool enable)
{
	this->enable = enable;
}


void MenuItem::action()
{
	
}

string MenuItem::identify()
{
	string message = this->getName() + "\n\n" +
	this->getTitle() + "\n" +
	"####################################" + "\n\n" +
	this->getDescription();

	return message;
}