#ifndef FileHelperTest_h__
#define FileHelperTest_h__

#include <iostream>
#include "../../../testLib/UnitTestSuite.h"

using namespace std;

void test__createFile__return_correct_result__success();

void test__exists__return_correct_result__success();
void test__exists__return_correct_result__failure();

void test_filenameExt_return_correct_result__success();
void test_filenameExt_return_correct_result__failure();

void test_filename_return_correct_result__success();
void test_filename_return_correct_result__failure();

void test_extension_return_correct_result__success();
void test_extension_return_correct_result__failure();

void test__lineCount__return_correct_result__success();
void test__lineCount__return_correct_result__failure();

void test__appendLineFileToFile__file_exist__success();
void test__appendLineFileToFile__file_not_exist__failure();

void test__readLastLines__file_exist__success();
void test__readLastLines__ask_more_than_count__success();
void test__readLastLines__file_not_exist__failure();

class FileHelperTest: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	FileHelperTest();
	virtual ~FileHelperTest();

};

#endif // FileHelperTest_h__
