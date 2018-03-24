#include "FileHelperTest.h"

#include "../../../testLib/Assertion.h"

#include "../../../../src/kernel/utils/FileHelper.h"

using namespace std;

FileHelperTest::FileHelperTest(): UnitTestSuite("FileHelper Test", 3)
{

}

FileHelperTest::~FileHelperTest()
{

}

void FileHelperTest::registerTests()
{
	registerCoveredMethod("filenameExt");
	registerCoveredMethod("filename");
	registerCoveredMethod("extension");

	registerTest("Test filenameExt return correct result", &test_filenameExt_return_correct_result__success);
	registerTest("Test filenameExt return correct result", &test_filenameExt_return_correct_result__failure);

	registerTest("Test filename return correct result", &test_filename_return_correct_result__success);
	registerTest("Test filename return correct result", &test_filename_return_correct_result__failure);

	registerTest("Test extension return correct result", &test_extension_return_correct_result__success);
	registerTest("Test extension return correct result", &test_extension_return_correct_result__failure);
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