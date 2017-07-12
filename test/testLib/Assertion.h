#ifndef Assertion_h__
#define Assertion_h__

#include <string>

#include "UnitTestFunction.h"

using namespace std;

void assertTrue(bool value);
void assertFalse(bool value);

void assertEqual(string val1, string val2);
void assertEqual(int val1, int val2);
void assertEqual(long val1, long val2);
void assertEqual(long long val1, long long val2);
void assertEqual(double val1, double val2);
void assertEqual(bool val1, bool val2);

bool assertMethod(string description, UnitTestFunction testFunction);

#endif // Assertion_h__
