#include "ArgumentList.h"

ArgumentList::ArgumentList(vector<Argument> args) : arguments(args)
{

}

ArgumentList::~ArgumentList()
{

}

const vector<Argument> ArgumentList::getArguments() const
{
    return arguments;
}
