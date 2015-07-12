#include <iostream>
#include <string>
#include "EulerProblemContainer.h"
#include "Problem001.cpp"
#include "Problem002.cpp"

using namespace std;

EulerProblemContainer::EulerProblemContainer()
{
	const int SIZE = 2;
	this->size = SIZE;
	this->problems = new EulerProblem *[SIZE];

	fillProblems();
}

EulerProblemContainer::~EulerProblemContainer()
{
	delete this->problems;
}

void EulerProblemContainer::fillProblems()
{
	this->problems[0] = new Problem001;
	this->problems[1] = new Problem002;
}

void EulerProblemContainer::showProblems()
{
	for (int i = 0; i < size; ++i)
	{
		EulerProblem *current = this->problems[i];
		cout << current->getId() << ". " 
			<< current->getName() << endl;
	}

	cout << endl << -1 << ". Exit";
}

EulerProblem *EulerProblemContainer::findProblem(int id)
{
	if (id == -1)
		return NULL;

	EulerProblem *current;

	for (int i = 0; i < this->size; ++i)
	{
		current = this->problems[i];
		if (current->getId() == id)
		{
			return current;
		}
	}

	cout << "No such problem exists!!!" << endl << endl;
	cout << "Choose again: ";
	cin >> id;
	return this->findProblem(id);
}

void EulerProblemContainer::run()
{
	int id;
	this->showProblems();

	cout << endl << "Choose a problem: ";
	cin >> id;

	EulerProblem *selected = this->findProblem(id);
	if (selected != NULL)
	{
		cout << selected->identify();
		selected->findSolution();
	}
}