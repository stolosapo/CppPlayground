#include <stdio.h>
#include <string.h>

#include "ArgParser.h"

using namespace std;


const char* ArgParser::COMMAND_PREFIX = "--";

const char* ArgParser::HELP = "help";
const char* ArgParser::ID_PATH = "id-path";
const char* ArgParser::NAME_PATH = "name-path";

const char* const ArgParser::COMMANDS[] = {
	ArgParser::HELP,
	ArgParser::ID_PATH,
	ArgParser::NAME_PATH
};


ArgParser::ArgParser(int argc, char* argv[])
{
	this->count = argc;
	this->values = argv;
}


ArgParser::~ArgParser()
{

}


bool ArgParser::exists(const char* const array[], int size, string command)
{
	bool exist = false;

	for (int i = 0; i < size; ++i)
	{
		const char *current = array[i];

		if ((((string) current) == command))
		{
			exist = true;
			break;
		}
	}

	return exist;
}


bool ArgParser::validCommand(string command)
{
	return exists(COMMANDS, 3, command);
}


bool ArgParser::isCommand(string arg)
{
	int size = arg.size();
	int pref_size = (int) strlen(COMMAND_PREFIX);

	if (size <= pref_size)
	{
		return false;
	}

	for (int i = 0; i < pref_size; ++i)
	{
		if (COMMAND_PREFIX[i] != arg[i])
		{
			return false;
		}
	}

	return true;
}


string ArgParser::trimCommand(string command)
{
	int size = command.size();
	int pref_size = (int) strlen(COMMAND_PREFIX);
	int len = size - pref_size;

	return command.substr(pref_size, len);
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


	bool is_command = false;

	string cur_command = "";
	string command = "";
	string param = "";

	for (int i = 1; i < count; ++i)
	{
		string arg(values[i]);
		is_command = isCommand(arg);

		if (is_command)
		{
			cur_command = trimCommand(arg);

			if (!validCommand(cur_command))
			{
				continue;
			}

			command = cur_command;
			param = "";
		}
		else
		{
			param = arg;
		}
	}
}


ArgumentList ArgParser::parseArgs()
{
    vector<Argument> arguments;

    if (count == 0)
	{
		return ArgumentList(arguments);
	}

	string execName = values[0];

	if (count == 1)
	{
		return ArgumentList(arguments);
	}

	string prev_command = "";
    bool is_prev_command = false;

	for (int i = 1; i < count; ++i)
	{
		string arg(values[i]);
		bool is_command = isCommand(arg);

		if (is_command)
		{
            if (is_prev_command || i == (count - 1))
            {
                Argument a = Argument(prev_command, "");
                arguments.push_back(a);
            }

            prev_command = trimCommand(arg);
		}
		else
		{
            Argument a = Argument(prev_command, arg);
            arguments.push_back(a);
		}

        is_prev_command = is_command;
	}

    return ArgumentList(arguments);
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

    ArgumentList arg_list = parseArgs();

    vector<Argument> list = arg_list.getArguments();

    for (int i = 0; i < list.size(); ++i)
	{
        Argument a = list.at(i);
		cout << i << ") " << a.getArgc() << " = " << a.getArgv() << endl;
	}
}


bool ArgParser::isHelp()
{
	return this->is_help;
}


bool ArgParser::isIdPath()
{
	return this->is_idPath;
}


bool ArgParser::isNamePath()
{
	return this->is_namePath;
}


char** ArgParser::getIdPath()
{
	return this->id_path;
}


char** ArgParser::getNamePath()
{
	return this->name_path;
}
