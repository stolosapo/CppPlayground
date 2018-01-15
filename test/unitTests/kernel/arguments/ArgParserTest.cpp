#include "ArgParserTest.h"

#include "../../../testLib/Assertion.h"

#include "../../../../src/kernel/arguments/ArgParser.h"

ArgParserTest::ArgParserTest(): UnitTestSuite("Argument Parser Test Suite", 13)
{

}

ArgParserTest::~ArgParserTest()
{

}

void ArgParserTest::registerTests()
{
	registerCoveredMethod("parse");
	registerCoveredMethod("getExecutableName");

	registerTest("Test Executable Name", &test_arg_parser_executable_name);
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