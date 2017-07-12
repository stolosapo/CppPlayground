#include <iostream>
#include <stdlib.h>

#include "unitTests/MainTestSuite.h"

using namespace std;


int main(int argc, char* argv[])
{
	bool passed = true;

	cout << endl ;
	cout << "Starting Unit Tests.." << endl ;
	cout << endl ;

	MainTestSuite* ttt = new MainTestSuite;

	ttt->test();

	passed &= ttt->report();

	cout << "Total test: (" << ttt->getPassedCount() << "/" << ttt->getCount() << ")" << endl;

	if (!passed)
	{
		exit(EXIT_FAILURE);
	}
}