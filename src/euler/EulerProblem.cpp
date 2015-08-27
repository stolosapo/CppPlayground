#include <iostream>
#include <string>
#include "EulerProblem.h"

using namespace std;

/*********************************
*
*		CONSTRUCTORS
*
**********************************/
EulerProblem::EulerProblem(
	ILogService *logSrv, 
	int id, 
	string name, 
	string title, 
	string description) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(id);
	this->setName(name);
	this->setTitle(title);
	this->setDescription(description);

	this->showOutput = true;
	this->showExample = true;
	this->solved = false;
}

EulerProblem::~EulerProblem()
{

}


/*********************************
*
*		GETTERS SETTERS
*
**********************************/

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

bool EulerProblem::isSolved()
{
	return solved;
}

void EulerProblem::setShowOutput(bool showOutput)
{
	this->showOutput = showOutput;
}

void EulerProblem::setShowExample(bool showExample)
{
	this->showExample = showExample;
}



/*********************************
*
*		PROTECTED METHODS
*
**********************************/

void EulerProblem::beforeSolve()
{

}

void EulerProblem::afterSolve()
{

}

int EulerProblem::example()
{
	
}

void EulerProblem::output(string message)
{
	if (this->showOutput)
	{
		this->logSrv->outString(message);
	}
}



/*********************************
*
*		PUBLIC METHODS
*
**********************************/

void EulerProblem::action()
{
	logSrv->outString("\n\n");
	logSrv->outString("################\n");
	logSrv->outString("### SOLUTION ###\n");
	logSrv->outString("################\n\n");

	this->beforeSolve();

	if (this->showExample)
	{
		logSrv->outString("Example : ");
		logSrv->outInt(this->example());
		logSrv->outString("\n");
	}

	this->solution = solve();

	logSrv->outInt(solution);
	logSrv->outString("\n");


	this->afterSolve();

	logSrv->outString("\n\n");
	logSrv->outString("################\n\n");
}