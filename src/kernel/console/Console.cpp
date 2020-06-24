#include <iostream>
#include <string>
#include <limits>

#include "Console.h"

using namespace std;

Console::Console()
{

}

Console::~Console()
{

}

int Console::inInt()
{
	int num;

	cin >> num;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return num;
}

string Console::inString()
{
	string message;

	cin >> message;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	return message;
}

string Console::inLine()
{
	string s;

	getline(cin , s);

	return s;
}

void Console::outInt(int number)
{
	cout << number;
}

void Console::outIntln(int number)
{
	cout << number << endl;
}

void Console::outString(string message)
{
	cout << message;
}

void Console::outStringln(string message)
{
	cout << message << endl;
}
