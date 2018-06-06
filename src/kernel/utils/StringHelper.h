#ifndef StringHelper_h__
#define StringHelper_h__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StringHelper
{
public:
	StringHelper();
	virtual ~StringHelper();

	static vector<string> split(const string& str, const string& delimiter);

};

#endif // StringHelper_h__