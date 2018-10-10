#include <stdio.h>
#include <string.h>

#include "ArgParser.h"

using namespace std;


const char* ArgParser::COMMAND_PREFIX = "--";

ArgParser::ArgParser()
{

}

ArgParser::~ArgParser()
{

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

ArgumentList ArgParser::parse(int argc, char* argv[])
{
    vector<Argument> arguments;

    if (argc == 0)
	{
		return ArgumentList(arguments);
	}

	string execName = argv[0];

	if (argc == 1)
	{
		return ArgumentList(arguments);
	}

	string prev_command = "";
    bool is_prev_command = false;

	for (int i = 1; i < argc; ++i)
	{
		string arg(argv[i]);
		bool is_command = isCommand(arg);

		if (is_command)
		{
            if (is_prev_command)
            {
                Argument a = Argument(prev_command, "");
                arguments.push_back(a);
            }

            prev_command = trimCommand(arg);

            if (i == (argc - 1))
            {
                Argument a = Argument(prev_command, "");
                arguments.push_back(a);
            }
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

void ArgParser::print(int argc, char* argv[])
{
	ArgumentList arg_list = parse(argc, argv);

    vector<Argument> list = arg_list.getArguments();

    for (int i = 0; i < list.size(); ++i)
	{
        Argument a = list.at(i);
		cout << i << ") " << a.getArgc() << " = " << a.getArgv() << endl;
	}
}
