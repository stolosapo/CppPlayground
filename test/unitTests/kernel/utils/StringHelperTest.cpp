#include "StringHelperTest.h"

#include <iostream>
#include <string>
#include <vector>

#include "../../../testLib/Assertion.h"

#include "../../../../src/kernel/utils/StringHelper.h"

using namespace std;

StringHelperTest::StringHelperTest(): UnitTestSuite("StringHelper Test", 2)
{

}

StringHelperTest::~StringHelperTest()
{

}

void StringHelperTest::registerTests()
{
	registerCoveredMethod("split");
	registerCoveredMethod("pad");
	registerCoveredMethod("removeStart");

	registerTest("Test split method return correct result size", &test_split_return_correct_result_count);
	registerTest("Test split method return correct results", &test_split_return_correct_results);

    registerTest("Test pad method return correct result when times is possitive", &test__pad__return_correct_result__possitive);
	registerTest("Test pad method return wrong result when times is zero", &test__pad__return_correct_result__zero);
	registerTest("Test pad method return wrong result when times is negative", &test__pad__return_correct_result__negative);

    registerTest("Test removeStart method return correct result when substring exists", &test__removeStart__return_correct_result__string_exist);
    registerTest("Test removeStart method return correct result when substring not exists", &test__removeStart__return_correct_result__string_not_exist);
    registerTest("Test removeStart method return correct result when substring is empty", &test__removeStart__return_correct_result__string_is_empty);
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

void test__pad__return_correct_result__possitive()
{
    string result = StringHelper::pad("*", 5);
    assertEqual("*****", result);
}

void test__pad__return_correct_result__zero()
{
    string result = StringHelper::pad("*", 0);
    assertEqual("", result);
}

void test__pad__return_correct_result__negative()
{
    string result = StringHelper::pad("*", -1);
    assertEqual("", result);
}

void test__removeStart__return_correct_result__string_exist()
{
    string result = StringHelper::removeStart("/home/user/a/path/to/a/file.mp3", "/home/user/a/path/to/a/");
    assertEqual("file.mp3", result);
}

void test__removeStart__return_correct_result__string_not_exist()
{
    string result = StringHelper::removeStart("/home/user/a/path/to/a/file.mp3", "/home/user/a/path/to/b/");
    assertEqual("/home/user/a/path/to/a/file.mp3", result);
}

void test__removeStart__return_correct_result__string_is_empty()
{
    string result = StringHelper::removeStart("/home/user/a/path/to/a/file.mp3", "");
    assertEqual("/home/user/a/path/to/a/file.mp3", result);
}
