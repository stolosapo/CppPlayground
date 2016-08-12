#ifndef ArgParser_h__
#define ArgParser_h__

#include <iostream>
#include <string>

using namespace std;

class ArgParser
{
private:
	static const char* COMMAND_PREFIX;
	
	static const char* HELP;
	static const char* ID_PATH;

	static const char* const COMMANDS[];

	int count;
	char** values;
	string executableName;

	bool is_help;
	bool is_idPath;
	char** id_path;

public:
	ArgParser(int argc, char* argv[]);
	virtual ~ArgParser();

	string getExecutableName();

	void parse();
	void printArgs();
	void printParsed();

	bool isHelp();
	bool isIdPath();
	char** getIdPath();
	
};

#endif // ArgParser_h__
