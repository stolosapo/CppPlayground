#ifndef Logger_h__
#define Logger_h__

#include <iostream>
#include <string>

using namespace std;

void logPassed(string message);
void logFailed(string message);
void logIgnored(string message);

void logTestResults(bool ignored, bool passed, string message);

#endif // Logger_h__
