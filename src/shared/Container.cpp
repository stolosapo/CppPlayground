#include <iostream>
#include <vector>
#include "Container.h"

using namespace std;

Container::Container(int id, string name, string caption, string exitCode) 
{
	this->id = id;
	this->name = name;
	this->caption = caption;
	this-> enable = true;
	this->exitCode = exitCode;
	this->useOptions = true;
	this->question = "Give option: ";
}

Container::~Container()
{

}

int Container::getId()
{
	return this->id;
}

string Container::getName()
{
	return this->name;
}

string Container::getCaption()
{
	return this->caption;
}

bool Container::getEnable()
{
	return this->enable;
}

void Container::setEnable(bool enable)
{
	this->enable = enable;
}

void Container::clearScreen()
{
	cout << string(50, '\n');
}

int Container::promptQuestion()
{
	cout << question;
	cin >> this->selection;

	return this->selection;
}

void Container::run()
{
	while(1)
	{
		this->clearScreen();

		this->showOptions();

		this->promptQuestion();

		this->execute(this->selection);
	}
}