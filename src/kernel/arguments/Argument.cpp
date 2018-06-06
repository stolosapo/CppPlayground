#include "Argument.h"

Argument::Argument(const char* argc, const char* argv) : argc(argc), argv(argv)
{

}

Argument::~Argument()
{

}

const char* Argument::getArgc() const
{
        return argc;
}

const char* Argument::getArgv() const
{
        return argv;
}
