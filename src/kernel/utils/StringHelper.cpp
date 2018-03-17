#include "StringHelper.h"

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