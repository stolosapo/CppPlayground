#ifndef ArgumentList_h__
#define ArgumentList_h__

#include <vector>
#include <string>

#include "Argument.h"

using namespace std;

class ArgumentList
{
private:
    vector<Argument> arguments;

public:
	ArgumentList(vector<Argument> args);
	virtual ~ArgumentList();

	const vector<Argument> getArguments() const;

    int size() const;
    bool exist(string name) const;
    string get(string name) const;
};

#endif // ArgumentList_h__
