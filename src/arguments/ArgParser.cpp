#include "ArgParser.h"

using namespace std;


ArgParser::ArgParser(int argc, char* argv[])
{
	this->count = argc;
	this->values = argv;
}


ArgParser::~ArgParser()
{

}


string ArgParser::getExecutableName()
{
	return this->executableName;
}


void ArgParser::parse()
{
	if (count > 0)
	{
		executableName = values[0];
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