#include "StringHelperTest.h"

#include <iostream>
#include <string>
#include <vector>

#include "../../../testLib/Assertion.h"

#include "../../../../src/kernel/utils/StringHelper.h"

using namespace std;

StringHelperTest::StringHelperTest(): UnitTestSuite("StringHelper Test", 1)
{

}

StringHelperTest::~StringHelperTest()
{

}

void StringHelperTest::registerTests()
{
	registerCoveredMethod("split");

	registerTest("Test split method return correct result size", &test_split_return_correct_result_count);
	registerTest("Test split method return correct results", &test_split_return_correct_results);
}

void test_split_return_correct_result_count()
{
	string str = "this/is/a/file/path.mp3";
	string delimiter = "/";

	vector<string> result = StringHelper::split(str, delimiter);

	assertEqual(result.size(), 5);
}

void test_split_return_correct_results()
{
	string str = "this/is/a/file/path.mp3";
	string delimiter = "/";

	vector<string> result = StringHelper::split(str, delimiter);

	assertEqual(result.at(0), "this");
	assertEqual(result.at(1), "is");
	assertEqual(result.at(2), "a");
	assertEqual(result.at(3), "file");
	assertEqual(result.at(4), "path.mp3");
}