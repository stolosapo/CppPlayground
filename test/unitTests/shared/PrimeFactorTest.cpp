#include "PrimeFactorTest.h"

#include <vector>

#include "../../testLib/Assertion.h"

#include "../../../src/shared/PrimeFactor.h"

using namespace std;

PrimeFactorTest::PrimeFactorTest(): UnitTestSuite("PrimeFactor Test Suite")
{

}

PrimeFactorTest::~PrimeFactorTest()
{

}

void PrimeFactorTest::registerTests()
{
        registerTest("Test Prime Factor up to correct size", &test_prime_factor_up_to_correct_size);
        registerTest("Test Prime Factor up to correct index", &test_prime_factor_up_to_correct_index);
        registerTest("Test Prime Factor get by index", &test_prime_factor_get_by_index);
        ignoreTest("Test Prime Factor get next prime", &test_prime_factor_get_next_prime);
        ignoreTest("Test Prime Factor is prime", &test_prime_factor_is_prime);
}

void test_prime_factor_up_to_correct_size()
{
        /*
        2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97
        =25
        */

        vector<int> v = PrimeFactor::upTo(100);

        assertEqual(v.size(), 25);
}

void test_prime_factor_up_to_correct_index()
{
        /*
        2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97
        =25
        */

        vector<int> v = PrimeFactor::upTo(100);

        assertEqual(v[0], 2);
        assertEqual(v[1], 3);
        assertEqual(v[2], 5);
        assertEqual(v[3], 7);
        assertEqual(v[4], 11);
        assertEqual(v[5], 13);
        assertEqual(v[6], 17);
        assertEqual(v[7], 19);
        assertEqual(v[8], 23);
        assertEqual(v[9], 29);
        assertEqual(v[10], 31);
}

void test_prime_factor_get_by_index()
{
        /*
        2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97
        =25
        */

        assertEqual(PrimeFactor::getByIndex(1), 2);
        assertEqual(PrimeFactor::getByIndex(2), 3);
        assertEqual(PrimeFactor::getByIndex(3), 5);
        assertEqual(PrimeFactor::getByIndex(4), 7);
        assertEqual(PrimeFactor::getByIndex(5), 11);
        assertEqual(PrimeFactor::getByIndex(6), 13);
        assertEqual(PrimeFactor::getByIndex(7), 17);
        assertEqual(PrimeFactor::getByIndex(8), 19);
        assertEqual(PrimeFactor::getByIndex(9), 23);
        assertEqual(PrimeFactor::getByIndex(10), 29);
        assertEqual(PrimeFactor::getByIndex(11), 31);
}

void test_prime_factor_get_next_prime()
{

}

void test_prime_factor_is_prime()
{

}
