#ifndef EulerProblem_h__
#define EulerProblem_h__

#include <iostream>
#include <string>
#include "../menu/MenuItem.h"
#include "../log/ILogService.h"

using namespace std;

class EulerProblem : public MenuItem
{
private:
	int solution;

	ILogService *logSrv;

protected:
	bool showOutput;
	bool showExample;
	bool solved;

	virtual void beforeSolve();
	virtual void afterSolve();
	virtual int example();

	virtual int solve() = 0;
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
	int getSolution();
	bool isSolved();

	void setShowOutput(bool showOutput);
	void setShowExample(bool showExample);

	virtual void action();
};

#endif // EulerProblem_h__