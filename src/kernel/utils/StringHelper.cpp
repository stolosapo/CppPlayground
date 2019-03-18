#include "StringHelper.h"

#include <stdio.h>
#include <stdarg.h>

StringHelper::StringHelper()
{

}

StringHelper::~StringHelper()
{

}

vector<string> StringHelper::split(const string& str, const string& delimiter)
{
	vector<string> result;

	string s(str);

	size_t pos = 0;
	string token;

	while ((pos = s.find(delimiter)) != string::npos)
	{
		token = s.substr(0, pos);

		result.push_back(token);

		s.erase(0, pos + delimiter.length());
	}

	result.push_back(s);

	return result;
}

// string StringHelper::format(const string& pattern, int numOfArgs, ...)
// {
//     va_list args;
//     va_start(args, numOfArgs);
//
//     string mess = format(pattern, args);
//
//     va_end(args);
//
//     return mess;
// }
//
// string StringHelper::format(const string& pattern, va_list args)
// {
//     char* mess = new char[1024];
//
//     sprintf(mess, pattern.c_str(), args);
//
//     string res = string(mess);
//
//     delete mess;
//
//     return res;
// }

string StringHelper::pad(const string& str, int times)
{
    string mess = "";

    for (int i = 0; i < times; i++)
    {
        mess += str;
    }

    return mess;
}
