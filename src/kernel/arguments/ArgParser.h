#ifndef ArgParser_h__
#define ArgParser_h__

#include <iostream>
#include <string>

#include "ArgumentList.h"

using namespace std;

class ArgParser
{
private:
	static const char* COMMAND_PREFIX;

	bool isCommand(string arg);
	string trimCommand(string command);

public:
	ArgParser();
	virtual ~ArgParser();

    ArgumentList parse(int argc, char* argv[]);
	void print(int argc, char* argv[]);
};

#endif // ArgParser_h__
