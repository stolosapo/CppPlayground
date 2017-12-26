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
	static const char* NAME_PATH;

	static const char* const COMMANDS[];

	int count;
	char** values;
	string executableName;

	bool is_help;
	bool is_idPath;
	bool is_namePath;
	char** id_path;
	char** name_path;

	bool exists(const char* const array[], int size, string command);
	bool validCommand(string command);
	bool isCommand(string arg);
	string trimCommand(string command);

public:
	ArgParser(int argc, char* argv[]);
	virtual ~ArgParser();

	string getExecutableName();

	void parse();
	void printArgs();
	void printParsed();

	bool isHelp();
	bool isIdPath();
	bool isNamePath();
	char** getIdPath();
	char** getNamePath();
	
};

#endif // ArgParser_h__
