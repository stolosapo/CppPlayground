#include "FileHelperTest.h"

#include "../../../testLib/Assertion.h"
#include "../../../testLib/FileUtils.h"

#include "../../../../src/kernel/utils/FileHelper.h"

using namespace std;

FileHelperTest::FileHelperTest(): UnitTestSuite("FileHelper Test", 10)
{

}

FileHelperTest::~FileHelperTest()
{

}

void FileHelperTest::registerTests()
{
	registerCoveredMethod("createFile");
	registerCoveredMethod("exists");
	registerCoveredMethod("filenameExt");
	registerCoveredMethod("filename");
	registerCoveredMethod("extension");
	registerCoveredMethod("lineCount");
	registerCoveredMethod("appendLineFileToFile");
	registerCoveredMethod("readLastLines");

    registerTest("Test createFile return correct result", &test__createFile__return_correct_result__success);

    registerTest("Test exists return correct result", &test__exists__return_correct_result__success);
	registerTest("Test exists return correct result", &test__exists__return_correct_result__failure);

	registerTest("Test filenameExt return correct result", &test_filenameExt_return_correct_result__success);
	registerTest("Test filenameExt return correct result", &test_filenameExt_return_correct_result__failure);

	registerTest("Test filename return correct result", &test_filename_return_correct_result__success);
	registerTest("Test filename return correct result", &test_filename_return_correct_result__failure);

	registerTest("Test extension return correct result", &test_extension_return_correct_result__success);
	registerTest("Test extension return correct result", &test_extension_return_correct_result__failure);

    registerTest("Test lineCount return correct result", &test__lineCount__return_correct_result__success);
	registerTest("Test lineCount return correct result", &test__lineCount__return_correct_result__failure);

    registerTest("Test appendLineFileToFile add line to the end when file exist", &test__appendLineFileToFile__file_exist__success);
	registerTest("Test appendLineFileToFile creates file and append when file not exist", &test__appendLineFileToFile__file_not_exist__failure);

    registerTest("Test readLastLines return the correct lines when file exist", &test__readLastLines__file_exist__success);
    registerTest("Test readLastLines return the correct lines when ask more lines then file contains", &test__readLastLines__ask_more_than_count__success);
	registerTest("Test readLastLines return 0 lines when file not exist", &test__readLastLines__file_not_exist__failure);
}

void test__createFile__return_correct_result__success()
{
    FileHelper::createFile("test__createFile__return_correct_result__success.txt");
    assertTrue(fileExists("test__createFile__return_correct_result__success.txt"));
}

void test__exists__return_correct_result__success()
{
    createFile("test__exists__return_correct_result__success.txt");

    bool result = FileHelper::exists("test__exists__return_correct_result__success.txt");

    assertTrue(result);
}

void test__exists__return_correct_result__failure()
{
    bool result = FileHelper::exists("test__exists__return_correct_result__failure.txt");

    assertFalse(result);
}

void test_filenameExt_return_correct_result__success()
{
	string str = "this/is/a/file/path.mp3";

	string result = FileHelper::filenameExt(str.c_str());

	assertEqual(result, "path.mp3");
}

void test_filenameExt_return_correct_result__failure()
{
	string str = "";

	string result = FileHelper::filenameExt(str.c_str());

	assertEqual(result, "");
}

void test_filename_return_correct_result__success()
{
	string str = "this/is/a/file/path.mp3";

	string result = FileHelper::filename(str.c_str());

	assertEqual(result, "path");
}

void test_filename_return_correct_result__failure()
{
	string str = "this/is/a/file/path";

	string result = FileHelper::filename(str.c_str());

	assertEqual(result, "path");
}

void test_extension_return_correct_result__success()
{
	string str = "this/is/a/file/path.mp3";

	string result = FileHelper::extension(str.c_str());

	assertEqual(result, "mp3");
}

void test_extension_return_correct_result__failure()
{
	string str = "this/is/a/file/path";

	string result = FileHelper::extension(str.c_str());

	assertEqual(result, "");
}

void test__lineCount__return_correct_result__success()
{
    createFile("test_file.txt");
    addLineToFile("test_file.txt", "ena");
    addLineToFile("test_file.txt", "dyo");
    addLineToFile("test_file.txt", "tria");

    int cnt = FileHelper::lineCount("test_file.txt");

    assertEqual(cnt, 3);
}

void test__lineCount__return_correct_result__failure()
{
    int cnt = FileHelper::lineCount("non_test_file.txt");

    assertEqual(cnt, 0);
}

void test__appendLineFileToFile__file_exist__success()
{
    createFile("test__appendLineFileToFile__file_exist__success.txt");

    FileHelper::appendLineFileToFile("test__appendLineFileToFile__file_exist__success.txt", "something");

    vector<string> lines = readLinesFromFile("test__appendLineFileToFile__file_exist__success.txt");

    assertTrue(lines.size() != 0);

    string lastLine = lines.at(lines.size() - 1);

    assertEqual(lastLine, "something");
}

void test__appendLineFileToFile__file_not_exist__failure()
{
    FileHelper::appendLineFileToFile("test__appendLineFileToFile__file_not_exist__failure.txt", "something_else");

    vector<string> lines = readLinesFromFile("test__appendLineFileToFile__file_not_exist__failure.txt");

    assertTrue(lines.size() != 0);

    string lastLine = lines.at(lines.size() - 1);

    assertEqual(lastLine, "something_else");
}

void test__readLastLines__file_exist__success()
{
    createFile("test__readLastLines__file_exist__success.txt");

    addLineToFile("test__readLastLines__file_exist__success.txt", "ena");
    addLineToFile("test__readLastLines__file_exist__success.txt", "dyo");
    addLineToFile("test__readLastLines__file_exist__success.txt", "tria");

    vector<string> results = FileHelper::readLastLines("test__readLastLines__file_exist__success.txt", 2);

    assertEqual(results.size(), 2);
    assertEqual(results.at(0), "dyo");
    assertEqual(results.at(1), "tria");
}

void test__readLastLines__ask_more_than_count__success()
{
    createFile("test__readLastLines__ask_more_than_count__success.txt");

    addLineToFile("test__readLastLines__ask_more_than_count__success.txt", "ena");
    addLineToFile("test__readLastLines__ask_more_than_count__success.txt", "dyo");
    addLineToFile("test__readLastLines__ask_more_than_count__success.txt", "tria");

    vector<string> results = FileHelper::readLastLines("test__readLastLines__ask_more_than_count__success.txt", 10);

    assertEqual(results.size(), 3);
    assertEqual(results.at(0), "ena");
    assertEqual(results.at(1), "dyo");
    assertEqual(results.at(2), "tria");
}

void test__readLastLines__file_not_exist__failure()
{
    vector<string> results = FileHelper::readLastLines("test__readLastLines__file_not_exist__failure.txt", 10);
    assertEqual(results.size(), 0);
}
