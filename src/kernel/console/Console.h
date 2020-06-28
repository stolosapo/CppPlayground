#ifndef Console_h__
#define Console_h__

#include <iostream>
#include <string>

using namespace std;

class Console
{
public:
	Console();
	virtual ~Console();

	static int inInt();
	static string inString();
	static string inLine();

    static void clearScreen();
    static void stringPrintf(const char* format, string arg...);
	static void outInt(int number);
	static void outIntln(int number);
	static void outString(string message);
	static void outStringln(string message);
};

#endif /* Console_h__ */
