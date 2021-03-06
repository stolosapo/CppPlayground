#ifndef EulerProblem_h__
#define EulerProblem_h__

#include <iostream>
#include <string>
#include "../kernel/converter/Convert.h"
#include "../kernel/console/Console.h"
#include "../kernel/menu/MenuItem.h"
#include "../kernel/log/ILogService.h"

using namespace std;

template<typename T>
class EulerProblem : public MenuItem
{
private:
	T solution;
	T correctAnswer;

	ILogService *logSrv;

protected:
	bool showOutput;
	bool showExample;
	bool solved;

	T getCorrectAnswer();
	void setCorrectAnswer(T correctAnswer);

	virtual void beforeSolve();
	virtual void afterSolve();
	virtual T example() = 0;

	virtual T solve() = 0;
	virtual void output(string message);

public:
	EulerProblem(
		ILogService *logSrv,
		int id,
		string name,
		string title,
		string description);
	virtual ~EulerProblem();

	bool getShowOutput();
	bool getShowExample();
	T getSolution();
	bool isSolved();

	void setShowOutput(bool showOutput);
	void setShowExample(bool showExample);

	virtual void action();
};








/*********************************
*
*		CONSTRUCTORS
*
**********************************/
template <typename T>
EulerProblem<T>::EulerProblem(
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

template <typename T>
EulerProblem<T>::~EulerProblem()
{

}



/*********************************
*
*		GETTERS SETTERS
*
**********************************/

template <typename T>
bool EulerProblem<T>::getShowOutput()
{
	return showOutput;
}

template <typename T>
bool EulerProblem<T>::getShowExample()
{
	return showExample;
}

template <typename T>
T EulerProblem<T>::getSolution()
{
	return solution;
}

template <typename T>
bool EulerProblem<T>::isSolved()
{
	return solved;
}

template <typename T>
T EulerProblem<T>::getCorrectAnswer()
{
	return correctAnswer;
}



template <typename T>
void EulerProblem<T>::setShowOutput(bool showOutput)
{
	this->showOutput = showOutput;
}

template <typename T>
void EulerProblem<T>::setShowExample(bool showExample)
{
	this->showExample = showExample;
}

template <typename T>
void EulerProblem<T>::setCorrectAnswer(T correctAnswer)
{
	this->correctAnswer = correctAnswer;
}






/*********************************
*
*		PROTECTED METHODS
*
**********************************/

template <typename T>
void EulerProblem<T>::beforeSolve()
{

}

template <typename T>
void EulerProblem<T>::afterSolve()
{

}

template <typename T>
void EulerProblem<T>::output(string message)
{
	if (this->showOutput)
	{
		Console::outString(message);
	}
}





/*********************************
*
*		PUBLIC METHODS
*
**********************************/

template <typename T>
void EulerProblem<T>::action()
{
	Console::outString("\n\n");
	Console::outString("################\n");
	Console::outString("### SOLUTION ###\n");
	Console::outString("################\n\n");

	this->beforeSolve();

	if (this->showExample)
	{
		string exampleSolution = Convert<T>::NumberToString(this->example());

		Console::outString("Example : ");
		Console::outStringln(exampleSolution);
	}

	this->solution = solve();

	string strSolution = Convert<T>::NumberToString(this->solution);

	Console::outStringln(strSolution);

	this->afterSolve();

	Console::outString("\n\n");
	Console::outString("################\n\n");
}
#endif // EulerProblem_h__
