#ifndef EulerProblemContainer_h__
#define EulerProblemContainer_h__

#include <iostream>
#include <string>
#include "EulerProblem.h"

using namespace std;

class EulerProblemContainer
{
private:
	EulerProblem **problems;
	int size;

	void fillProblems();
	void showProblems();
	EulerProblem *findProblem(int id);
	void clearScreen();

public:
	EulerProblemContainer();
	virtual ~EulerProblemContainer();
	
	void run();
};

#endif // EulerProblemContainer_h__