#include <iostream>
#include <stdlib.h>

#include "unitTests/MainTestSuite.h"

using namespace std;


int main(int argc, char* argv[])
{
	cout << endl ;
	cout << "Starting Unit Tests.." << endl ;
	cout << endl ;

	MainTestSuite* ttt = new MainTestSuite;

	ttt->test();

	bool passed = ttt->report();

	int count = ttt->getCount();
	int passes = ttt->getPassedCount();
	int ignored = ttt->getIgnoredCount();
	int failures = count - passes - ignored;

	cout << endl ;
	cout << "Results:" << endl << endl;
	cout << "Test run: " << count << ", Failures: " << failures << ", Skipped: " << ignored << endl;
	cout << endl ;

	if (!passed)
	{
		cout << "Tests exited with " << EXIT_FAILURE << endl;
		exit(EXIT_FAILURE);
	}
}
