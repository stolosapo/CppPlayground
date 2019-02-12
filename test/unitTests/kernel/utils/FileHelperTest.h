#ifndef FileHelperTest_h__
#define FileHelperTest_h__

#include <iostream>
#include "../../../testLib/UnitTestSuite.h"

using namespace std;

void test_filenameExt_return_correct_result__success();
void test_filenameExt_return_correct_result__failure();

void test_filename_return_correct_result__success();
void test_filename_return_correct_result__failure();

void test_extension_return_correct_result__success();
void test_extension_return_correct_result__failure();

void test__lineCount__return_correct_result__success();
void test__lineCount__return_correct_result__failure();

class FileHelperTest: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	FileHelperTest();
	virtual ~FileHelperTest();

};

#endif // FileHelperTest_h__
