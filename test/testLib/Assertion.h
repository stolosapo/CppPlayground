#ifndef Assertion_h__
#define Assertion_h__

#include <string>

#include "UnitTestFunction.h"

using namespace std;

void assertTrue(bool value);
void assertFalse(bool value);
bool assertMethod(string description, UnitTestFunction testFunction);

#endif // Assertion_h__
