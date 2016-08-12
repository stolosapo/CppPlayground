#include "ArgParser.h"

using namespace std;


const char* ArgParser::COMMAND_PREFIX = "--";

const char* ArgParser::HELP = "help";
const char* ArgParser::ID_PATH = "id-path";

const char* const ArgParser::COMMANDS[] = {
	ArgParser::HELP,
	ArgParser::ID_PATH
};


ArgParser::ArgParser(int argc, char* argv[])
{
	this->count = argc;
	this->values = argv;
}


ArgParser::~ArgParser()
{
	for (int i = 0; i < count; ++i)
	{
		delete values[i];
	}

	delete[] values;
}


string ArgParser::getExecutableName()
{
	return this->executableName;
}


void ArgParser::parse()
{
	if (count == 0)
	{
		return;
	}

	executableName = values[0];

	if (count <= 1)
	{
		return;	
	}

	for (int i = 1; i < count; ++i)
	{
		
	}
}


void ArgParser::printArgs()
{
	cout << endl << "Arg count: " << count << endl << endl;

	for (int i = 0; i < count; ++i)
	{
		cout << i << ") " << values[i] << endl;
	}
}


void ArgParser::printParsed()
{
	cout << endl;
	cout << "Executable Name: " << getExecutableName() << endl;
}