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

	cout << endl ;
	cout << "Total test results: (" << ttt->getPassedCount() << "/" << ttt->getCount() << ")" << endl;
	cout << endl ;

	if (!passed)
	{
		exit(EXIT_FAILURE);
	}
}