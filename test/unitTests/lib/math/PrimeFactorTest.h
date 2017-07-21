#ifndef PrimeFactorTest_h__
#define PrimeFactorTest_h__

#include <iostream>
#include "../../../testLib/UnitTestSuite.h"

using namespace std;

void test_prime_factor_up_to_correct_size();
void test_prime_factor_up_to_correct_index();

void test_prime_factor_get_by_index();

void test_prime_factor_1_is_not_prime();
void test_prime_factor_2_is_prime();
void test_prime_factor_is_prime();
void test_prime_factor_is_not_prime();

void test_prime_factor_next_prime_of_0_is_2();
void test_prime_factor_next_prime_of_1_is_2();
void test_prime_factor_next_prime_of_2_is_3();
void test_prime_factor_next_prime_of_3_is_5();
void test_prime_factor_next_prime_of_other_number();

class PrimeFactorTest: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	PrimeFactorTest();
	virtual ~PrimeFactorTest();

};

#endif // PrimeFactorTest_h__
