#include <iostream>
#include <string>
#include <limits>

#include "InOut.h"

using namespace std;

InOut::InOut()
{

}

InOut::~InOut()
{

}

int InOut::inInt()
{
	int num;

	cin >> num;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return num;
}

string InOut::inString()
{
	string message;

	cin >> message;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return message;
}

string InOut::inLine()
{
	string s;

	getline(cin , s);

	return s;
}

void InOut::outInt(int number)
{
	cout << number;
}

void InOut::outString(string message)
{
	cout << message;
}
