#include "Argument.h"

Argument::Argument(const string& name, const string& value) : name(name), value(value)
{

}

Argument::Argument(const Argument& arg)
{
    name = arg.name;
    value = arg.value;
}

Argument::~Argument()
{

}

string Argument::getName() const
{
    return name;
}

string Argument::getValue() const
{
    return value;
}
