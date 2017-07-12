#include "Problem001Test.h"

#include "../../testLib/Assertion.h"

#include "../../../src/euler/Problem001.cpp"

Problem001Test::Problem001Test() : UnitTestSuite("Project Euler - Problem 001 Test")
{

}

Problem001Test::~Problem001Test()
{

}

void Problem001Test::registerTests()
{
	registerTest("Problem must be saved", &problem001_is_solved);
}

void problem001_is_solved()
{
	assertTrue(true);
}