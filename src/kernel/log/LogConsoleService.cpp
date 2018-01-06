#include <iostream>
#include <string>
#include "ILogService.h"
#include "../definitions/Colors.h"

using namespace std;

class LogConsoleService : public ILogService
{
public:
	LogConsoleService() : ILogService()
	{
		this->useColor = true;
	}

	~LogConsoleService()
	{

	}

	void clearScreen()
	{
		outString(string(50, '\n'));
	}

	void print(string message)
	{
		outString(message);
	}

	void printl(string message)
	{
		outString(message);
		outString("\n");
	}

	void printColor(string COLOR)
	{
		if (this->useColor)
		{
			outString(COLOR);
		}
	}

	void trace(string message)
	{
		printColor(BOLDGREEN);
		outString(" *** [ TRACE ]: ");

		printColor(WHITE);
		outString(message);
		outString("\n");

		printColor(RESET);
	}

	void info(string message)
	{
		printColor(BOLDYELLOW);
		outString(" *** [ INFO ]: ");

		printColor(WHITE);
		outString(message);
		outString("\n");

		printColor(RESET);
	}

	void debug(string message)
	{
		printColor(BOLDBLUE);
		outString(" *** [ DEBUG ]: ");

		printColor(WHITE);
		outString(message);
		outString("\n");

		printColor(RESET);
	}

	void warn(string message)
	{
		printColor(BOLDMAGENTA);
		outString(" *** [ WARN ]: ");

		printColor(WHITE);
		outString(message);
		outString("\n");

		printColor(RESET);
	}

	void error(string message)
	{
		printColor(BOLDRED);
		outString(" *** [ ERROR ]: ");

		printColor(WHITE);
		outString(message);
		outString("\n");

		printColor(RESET);
	}

	void fatal(string message)
	{
		printColor(BOLDRED);
		outString(" *** [ FATAL ]: ");

		printColor(WHITE);
		outString(message);
		outString("\n");

		// exit(1);

		printColor(RESET);
	}

	void test()
	{
		outString("Hello World!!");
	}
};