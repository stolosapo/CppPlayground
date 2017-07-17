#include "PrimeFactorTest.h"

#include <vector>

#include "../../testLib/Assertion.h"

#include "../../../src/shared/PrimeFactor.h"

using namespace std;

PrimeFactorTest::PrimeFactorTest(): UnitTestSuite("PrimeFactor Test Suite", 4)
{

}

PrimeFactorTest::~PrimeFactorTest()
{

}

void PrimeFactorTest::registerTests()
{
        registerCoveredMethod("upTo");
        registerCoveredMethod("getByIndex");
        registerCoveredMethod("getNextPrime");
        registerCoveredMethod("isPrime");
        

        registerTest("Test Prime Factor up to correct size", &test_prime_factor_up_to_correct_size);
        registerTest("Test Prime Factor up to correct index", &test_prime_factor_up_to_correct_index);

        registerTest("Test Prime Factor get by index", &test_prime_factor_get_by_index);

        registerTest("Test 1 is not a prime number", &test_prime_factor_1_is_not_prime);
        registerTest("Test 2 is a prime number", &test_prime_factor_2_is_prime);
        registerTest("Test other prime numbers", &test_prime_factor_is_prime);
        registerTest("Test other not prime numbers", &test_prime_factor_is_not_prime);
        
        registerTest("Test next prime number of 0 is 2", &test_prime_factor_next_prime_of_0_is_2);
        registerTest("Test next prime number of 1 is 2", &test_prime_factor_next_prime_of_1_is_2);
        registerTest("Test next prime number of 2 is 3", &test_prime_factor_next_prime_of_2_is_3);
        registerTest("Test next prime number of 3 is 5", &test_prime_factor_next_prime_of_3_is_5);
        registerTest("Test next prime number of other numbers", &test_prime_factor_next_prime_of_other_number);
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

void test_prime_factor_1_is_not_prime()
{
	assertFalse(PrimeFactor::isPrime(1));
}

void test_prime_factor_2_is_prime()
{
	assertTrue(PrimeFactor::isPrime(2));
}

void test_prime_factor_is_prime()
{
	assertTrue(PrimeFactor::isPrime(3));
	assertTrue(PrimeFactor::isPrime(5));
	assertTrue(PrimeFactor::isPrime(7));
}

void test_prime_factor_is_not_prime()
{
	assertFalse(PrimeFactor::isPrime(4));
	assertFalse(PrimeFactor::isPrime(6));
	assertFalse(PrimeFactor::isPrime(8));
}

void test_prime_factor_next_prime_of_0_is_2()
{
	assertEqual(PrimeFactor::getNextPrime(0), 2);
}

void test_prime_factor_next_prime_of_1_is_2()
{
	assertEqual(PrimeFactor::getNextPrime(1), 2);
}

void test_prime_factor_next_prime_of_2_is_3()
{
	assertEqual(PrimeFactor::getNextPrime(2), 3);
}

void test_prime_factor_next_prime_of_3_is_5()
{
	assertEqual(PrimeFactor::getNextPrime(3), 5);
}

void test_prime_factor_next_prime_of_other_number()
{
	assertEqual(PrimeFactor::getNextPrime(4), 5);
	assertEqual(PrimeFactor::getNextPrime(5), 7);
	assertEqual(PrimeFactor::getNextPrime(6), 7);
}