#include <iostream>
#include <string>
#include "EulerProblem.h"

using namespace std;

EulerProblem::EulerProblem(int id, string name, string title, string description)
{
	this->id = id;
	this->name = name;
	this->title = title;
	this->description = description;

	this->showOutput = true;
	this->showExample = true;
}

EulerProblem::~EulerProblem()
{

}

int EulerProblem::getId()
{
	return this->id;
}

string EulerProblem::getName()
{
	return name;
}

string EulerProblem::getTitle()
{
	return title;
}

string EulerProblem::getDescription()
{
	return description;
}

bool EulerProblem::getShowOutput()
{
	return showOutput;
}

bool EulerProblem::getShowExample()
{
	return showExample;
}

int EulerProblem::getSolution()
{
	return solution;
}

void EulerProblem::setShowOutput(bool showOutput)
{
	this->showOutput = showOutput;
}

void EulerProblem::setShowExample(bool showExample)
{
	this->showExample = showExample;
}

void EulerProblem::output(string message)
{
	if (this->showOutput)
	{
		cout << message;
	}
}

string EulerProblem::identify()
{
	string message = this->getName() + "\n\n" +
	this->getTitle() + "\n" +
	"####################################" + "\n\n" +
	this->getDescription();

	return message;
}

void EulerProblem::beforeSolve()
{

}

void EulerProblem::afterSolve()
{

}

int EulerProblem::example()
{
	
}

void EulerProblem::findSolution()
{
	cout << endl << endl
		<< "################" << endl
		<< "### SOLUTION ###" << endl
		<< "################" << endl << endl;

	this->beforeSolve();


	this->solution = solve();

	if (this->showExample)
	{
		cout << "Example : " << this->example() << endl;
	}

	cout << solution << endl;


	this->afterSolve();

	cout << endl << endl
		<< "################" << endl << endl;
}