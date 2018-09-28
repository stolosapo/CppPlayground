#include "Argument.h"

Argument::Argument(const string& argc, const string& argv) : argc(argc), argv(argv)
{

}

Argument::Argument(const Argument& arg)
{
    argc = arg.argc;
    argv = arg.argv;
}

Argument::~Argument()
{

}

string Argument::getArgc() const
{
    return argc;
}

string Argument::getArgv() const
{
    return argv;
}
