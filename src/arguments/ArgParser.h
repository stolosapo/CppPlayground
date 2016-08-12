#ifndef ArgParser_h__
#define ArgParser_h__

#include <iostream>
#include <string>

using namespace std;

class ArgParser
{
private:
	int count;
	char** values;
	string executableName;

public:
	ArgParser(int argc, char* argv[]);
	virtual ~ArgParser();

	string getExecutableName();

	void parse();
	void printArgs();
	void printParsed();
	
};

#endif // ArgParser_h__
