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

void EulerProblem::example()
{
	
}

void EulerProblem::findSolution()
{
	cout << endl << endl
		<< "################" << endl
		<< "### SOLUTION ###" << endl
		<< "################" << endl << endl;

	this->beforeSolve();

	this->example();

	this->solve();

	this->afterSolve();

	cout << endl << endl
		<< "################" << endl << endl;
}