#include "FigletHeaderTest.h"

#include "../../../testLib/Assertion.h"
#include "../../../testLib/FileUtils.h"

#include "../../../../src/kernel/utils/FileHelper.h"

#include "TestFigletHeader.cpp"

using namespace std;

FigletHeaderTest::FigletHeaderTest(): UnitTestSuite("FigletHeader Test", 2)
{

}

FigletHeaderTest::~FigletHeaderTest()
{

}

void FigletHeaderTest::registerTests()
{
	registerCoveredMethod("getHeader");

    registerTest("Test getHeader return correct result", &test__getHeader__return_correct_result__success);
    registerTest("Test getHeader return correct result when negative index", &test__getHeader__return_correct_result__when_negative_index);
    registerTest("Test getHeader return correct result when index larger than size", &test__getHeader__return_correct_result__when_index_largen_than_size);
}

void test__getHeader__return_correct_result__success()
{
    TestFigletHeader h;

    assertEqual(h.getHeader(0), "11111");
    assertEqual(h.getHeader(1), "22222");
    assertEqual(h.getHeader(2), "33333");
}

void test__getHeader__return_correct_result__when_negative_index()
{
    TestFigletHeader h;

    assertEqual(h.getHeader(-1), "11111");
}

void test__getHeader__return_correct_result__when_index_largen_than_size()
{
    TestFigletHeader h;

    assertEqual(h.getHeader(100), "11111");
}
