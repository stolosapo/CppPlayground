#ifndef EulerProblem_h__
#define EulerProblem_h__

#include <iostream>
#include <string>

using namespace std;

class EulerProblem
{
private:
	int id;
	string name;
	string title;
	string description;
	int solution;

protected:
	bool showOutput;
	bool showExample;

	virtual void beforeSolve();
	virtual void afterSolve();
	virtual int example();
	virtual int solve() = 0;
	virtual void output(string message);

public:
	EulerProblem(int id, string name, string title, string description);
	virtual ~EulerProblem();

	int getId();
	string getName();
	string getTitle();
	string getDescription();
	bool getShowOutput();
	bool getShowExample();
	int getSolution();

	void setShowOutput(bool showOutput);
	void setShowExample(bool showExample);

	virtual string identify();
	virtual void findSolution();
};

#endif // EulerProblem_h__