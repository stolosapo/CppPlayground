#include <iostream>
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

using namespace std;

#ifndef CONVERT_H_
#define CONVERT_H_

template<typename T>
class Convert 
{
public:	
	static string NumberToString(T Number);
	static T StringToNumber(const string &Text);
};

template <typename T>
string Convert<T>::NumberToString(T Number)
{
	ostringstream ss;
	ss << Number;
	return ss.str();
}

template <typename T>
T Convert<T>::StringToNumber(const string &Text)
{
	istringstream ss(Text);
	T result;
	return ss >> result ? result : 0;
}
#endif /* CONVERT_H_ */