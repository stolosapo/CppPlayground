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
	cout << endl 
		<< 0 << ". Exit"
		<< endl << endl;

	for (int i = 0; i < size; ++i)
	{
		EulerProblem *current = this->problems[i];
		cout << current->getId() << ". " 
			<< current->getName() << endl;
	}

	cout << endl;
}

EulerProblem *EulerProblemContainer::findProblem(int id)
{
	if (id == 0)
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

void EulerProblemContainer::clearScreen()
{
	cout << string(50, '\n');
}

void EulerProblemContainer::run()
{
	int id;
	string question;

	while (1)
	{
		clearScreen();
		this->showProblems();

		cout << endl << "Choose a problem: ";
		cin >> id;

		EulerProblem *selected = this->findProblem(id);
		if (selected != NULL)
		{
			clearScreen();
			cout << selected->identify();
			selected->findSolution();

			cout << endl << "Solve other problem ? (y/n): ";
			cin >> question;

			if (question != "y" && question != "Y")
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
}