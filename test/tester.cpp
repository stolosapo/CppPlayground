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
void test_arg_parser_executable_name();


int main(int argc, char* argv[])
{
	bool passed = true;

	cout << endl ;
	cout << "Starting Unit Tests.." << endl ;
	cout << endl ;

	passed &= assertMethod("Ena aplo TRUE - TRUE test", &ena_aplo_true_true_test);
	passed &= assertMethod("Ena aplo TRUE - FALSE test", &ena_aplo_true_false_test);
	passed &= assertMethod("Argument Parser: Test Executable Name", &test_arg_parser_executable_name);
	// passed &= assertMethod("Ena aplo FALSE - TRUE test", &ena_aplo_false_true_test);
	// passed &= assertMethod("Ena aplo FALSE - FALSE test", &ena_aplo_false_false_test);

	if (!passed)
	{
		exit(EXIT_FAILURE);
	}
}

void test_arg_parser_executable_name()
{
	const int SIZE = 4;
	int argc = SIZE;
	char* argv[SIZE];

	const char *arg0 = "./executable";
	const char *arg1 = "first";
	const char *arg2 = "second";
	const char *arg3 = "third";

	argv[0] = (char*) arg0;
	argv[1] = (char*) arg1;
	argv[2] = (char*) arg2;
	argv[3] = (char*) arg3;

	ArgParser* parser = new ArgParser(argc, argv);
	parser->parse();

	assertEqual(parser->getExecutableName(), argv[0]);
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
