#include <iostream>
#include <stdlib.h>

#include "testLib/UnitTest.h"
#include "testLib/Assertion.h"

#include "../src/arguments/ArgParser.h"

using namespace std;


void ena_aplo_true_true_test();
void ena_aplo_true_false_test();
void ena_aplo_false_true_test();
void ena_aplo_false_false_test();


int main(int argc, char* argv[])
{
	bool passed = true;

	cout << endl ;
	cout << "Starting Unit Tests.." << endl ;
	cout << endl ;

	passed &= assertMethod("Ena aplo TRUE - TRUE test", &ena_aplo_true_true_test);
	passed &= assertMethod("Ena aplo TRUE - FALSE test", &ena_aplo_true_false_test);
	// passed &= assertMethod("Ena aplo FALSE - TRUE test", &ena_aplo_false_true_test);
	// passed &= assertMethod("Ena aplo FALSE - FALSE test", &ena_aplo_false_false_test);

	if (!passed)
	{
		exit(EXIT_FAILURE);
	}
}

void ena_aplo_true_true_test()
{
	assertTrue(true);
}

void ena_aplo_true_false_test()
{
	assertFalse(false);
}

void ena_aplo_false_true_test()
{
	assertTrue(false);
}

void ena_aplo_false_false_test()
{
	assertFalse(true);
}