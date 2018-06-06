#include "ArgumentList.h"

ArgumentList::ArgumentList(list<Argument> args) : arguments(args)
{

}

ArgumentList::~ArgumentList()
{

}

const list<Argument> ArgumentList::getArguments() const
{
        return arguments;
}
