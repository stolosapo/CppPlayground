#include <iostream>
#include <string>
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

	return num;
}
	
string InOut::inString()
{
	string message;
	cin >> message;

	return message;
}

void InOut::outInt(int number)
{
	cout << number;
}

void InOut::outString(string message)
{
	cout << message;
}