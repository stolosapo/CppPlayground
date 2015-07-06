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

protected:
	virtual void beforeSolve();
	virtual void afterSolve();
	virtual void example();
	virtual void solve() = 0;

public:
	EulerProblem(int id, string name, string title, string description);
	virtual ~EulerProblem();

	int getId();
	string getName();
	string getTitle();
	string getDescription();

	virtual string identify();
	virtual void findSolution();
};

#endif // EulerProblem_h__