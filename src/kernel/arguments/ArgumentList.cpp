#include "ArgumentList.h"

#include <iostream>

using namespace std;

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

int ArgumentList::size() const
{
    return arguments.size();
}

bool ArgumentList::exist(string name) const
{
    cout << 1.1 << endl;
    for (int i = 0; i < arguments.size(); i++)
    {
        cout << 1.2 << "." << i << endl;
        cout << arguments.size() << endl;

        Argument arg = arguments.at(i);
        cout << 1.2 << "." << i << endl;

        if (arg.getName() == name)
        {
            cout << 1.2 << "." << i << endl;
            return true;
        }
    }

    return false;
}

string ArgumentList::get(string name) const
{
    cout << 1 << endl;
    if (!exist(name))
    {
        return "";
    }

    cout << 2 << endl;

    for (int i = 0; i < arguments.size(); i++)
    {
        Argument arg = arguments.at(i);

        if (arg.getName() == name)
        {
            return arg.getValue();
        }
    }

    return "";
}
