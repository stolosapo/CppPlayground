#include <iostream>
#include <string>
#include "ILogService.h"
#include "../definitions/Colors.h"
#include "../console/Console.h"

using namespace std;

class LogConsoleService : public ILogService
{
private:
    void printColor(string COLOR)
	{
		if (this->useColor)
		{
			Console::outString(COLOR);
		}
	}

public:
	LogConsoleService() : ILogService()
	{
		this->useColor = true;
	}

	~LogConsoleService()
	{

	}

	void trace(string message)
	{
		printColor(BOLDGREEN);
		Console::outString(" *** [ TRACE ]: ");

		printColor(WHITE);
		Console::outStringln(message);

		printColor(RESET);
	}

	void info(string message)
	{
		printColor(BOLDYELLOW);
		Console::outString(" *** [ INFO ]: ");

		printColor(WHITE);
		Console::outStringln(message);

		printColor(RESET);
	}

	void debug(string message)
	{
		printColor(BOLDBLUE);
		Console::outString(" *** [ DEBUG ]: ");

		printColor(WHITE);
		Console::outStringln(message);

		printColor(RESET);
	}

	void warn(string message)
	{
		printColor(BOLDMAGENTA);
		Console::outString(" *** [ WARN ]: ");

		printColor(WHITE);
		Console::outStringln(message);

		printColor(RESET);
	}

	void error(string message)
	{
		printColor(BOLDRED);
		Console::outString(" *** [ ERROR ]: ");

		printColor(WHITE);
		Console::outStringln(message);

		printColor(RESET);
	}

	void fatal(string message)
	{
		printColor(BOLDRED);
		Console::outString(" *** [ FATAL ]: ");

		printColor(WHITE);
		Console::outStringln(message);

		// exit(1);

		printColor(RESET);
	}

};
