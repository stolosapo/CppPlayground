#include "ConvertTest.h"

#include "../../testLib/Assertion.h"

#include "../../../src/shared/convert.h"

ConvertTest::ConvertTest(): UnitTestSuite("Convert Test Suite")
{

}

ConvertTest::~ConvertTest()
{

}

void ConvertTest::registerTests()
{
	registerTest("Test Convert int to string", &test_convert_int_to_string);
	registerTest("Test Convert long to string", &test_convert_long_to_string);
	registerTest("Test Convert long long to string", &test_convert_long_long_to_string);
	registerTest("Test Convert double to string", &test_convert_double_to_string);
	registerTest("Test Convert string to int", &test_convert_string_to_int);
	registerTest("Test Convert string to long", &test_convert_string_to_long);
	registerTest("Test Convert string to long_long", &test_convert_string_to_long_long);
	registerTest("Test Convert string to double", &test_convert_string_to_double);
}

void test_convert_int_to_string()
{
	int num = 256;

	string conv = Convert<int>::NumberToString(num);

	assertEqual("256", conv);
}

void test_convert_long_to_string()
{
	long num = 256;

	string conv = Convert<long>::NumberToString(num);

	assertEqual("256", conv);
}

void test_convert_long_long_to_string()
{
	long long num = 256;

	string conv = Convert<long long>::NumberToString(num);

	assertEqual("256", conv);
}

void test_convert_double_to_string()
{
	double num = 256.99;

	string conv = Convert<double>::NumberToString(num);

	assertEqual("256.99", conv);
}

void test_convert_string_to_int()
{
	int num = 256;
	string strNum = "256";

	int conv = Convert<int>::StringToNumber(strNum);

	assertEqual(num, conv);
}

void test_convert_string_to_long()
{
	long num = 256;
	string strNum = "256";

	long conv = Convert<long>::StringToNumber(strNum);

	assertEqual(num, conv);
}

void test_convert_string_to_long_long()
{
	long long num = 256;
	string strNum = "256";

	long long conv = Convert<long long>::StringToNumber(strNum);

	assertEqual(num, conv);
}

void test_convert_string_to_double()
{
	double num = 256;
	string strNum = "256";

	double conv = Convert<double>::StringToNumber(strNum);

	assertEqual(num, conv);
}
