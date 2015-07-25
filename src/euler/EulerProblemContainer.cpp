#include <iostream>
#include <string>
#include "EulerProblemContainer.h"
#include "Problem001.cpp"
#include "Problem002.cpp"
#include "Problem003.cpp"

using namespace std;

EulerProblemContainer::EulerProblemContainer() : Container(
	1, 
	"EulerProblems",
	"Euler Problems",
	1)
{

}

EulerProblemContainer::~EulerProblemContainer()
{

}

void EulerProblemContainer::execute(int menuItemId)
{
	// cout << selected->identify();
	// selected->findSolution();

	// cout << endl << "Solve other problem ? (y/n): ";
	// cin >> question;

	// if (question != "y" && question != "Y")
	// {
	// 	break;
	// }
}

void EulerProblemContainer::fillOptions()
{
	this->addMenuItem(0, NULL);
}