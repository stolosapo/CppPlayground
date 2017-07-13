#ifndef PrimeFactorTest_h__
#define PrimeFactorTest_h__

#include <iostream>
#include "../../testLib/UnitTestSuite.h"

using namespace std;

void test_prime_factor_up_to_correct_size();
void test_prime_factor_up_to_correct_index();
void test_prime_factor_get_by_index();
void test_prime_factor_get_next_prime();
void test_prime_factor_is_prime();

class PrimeFactorTest: public UnitTestSuite
{
protected:
	virtual void registerTests();

public:
	PrimeFactorTest();
	virtual ~PrimeFactorTest();

};

#endif // PrimeFactorTest_h__
