#include "ArgumentList.h"

ArgumentList::ArgumentList(list<Argument> args)
{
        // arguments = list<Argument>(args);
}

ArgumentList::~ArgumentList()
{

}

const list<Argument> ArgumentList::getArguments() const
{
        return arguments;
}
