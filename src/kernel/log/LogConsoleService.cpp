#include <iostream>
#include <string>
#include <stdio.h>
#include "ILogService.h"
#include "../definitions/Colors.h"

using namespace std;

class LogConsoleService : public ILogService
{
private:
	void colorTable(const char *title, const char *mode)
	{
		int f, b;
		printf("\n\033[1m%s\033[m\n bg\t fg\n", title);
		for (b = 40; b <= 107; b++) {
			if (b == 48) b = 100;
			printf("%3d\t\033[%s%dm", b, mode, b);
			for (f = 30; f <= 97; f++) {
				if (f == 38) f = 90;
				printf("\033[%dm%3d ", f, f);
			}
			puts("\033[m");
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

	void clearScreen()
	{
		outString(string(50, '\n'));
	}

	void print(string message)
	{
		outString(message);
	}

	void print(string message, string COLOR)
	{
		printColor(COLOR);

		print(message);

		printColor(RESET);
	}

	void printl(string message)
	{
		outString(message);
		outString("\n");
	}

	void printl(string message, string COLOR)
	{
		printColor(COLOR);

		print(message);

		printColor(RESET);

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

		/* With colors */
		int fg, bg, blink, inverse;
 
		colorTable("normal ( ESC[22m or ESC[m )", "22;");
		colorTable("bold ( ESC[1m )", "1;");
		colorTable("faint ( ESC[2m ), not well supported", "2;");
		colorTable("italic ( ESC[3m ), not well supported", "3;");
		colorTable("underline ( ESC[4m ), support varies", "4;");
		colorTable("blink ( ESC[5m )", "5;");
		colorTable("inverted ( ESC[7m )", "7;");
	}
};
