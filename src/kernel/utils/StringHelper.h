#ifndef StringHelper_h__
#define StringHelper_h__

#include <iostream>
#include <string>
#include <vector>
#include <stdarg.h>

using namespace std;

class StringHelper
{
public:
	StringHelper();
	virtual ~StringHelper();

	static vector<string> split(const string& str, const string& delimiter);
    // static string format(const string& pattern, int numOfArgs, ...);
    // static string format(const string& pattern, va_list args);
    static string pad(const string& str, int times);

};

#endif // StringHelper_h__
