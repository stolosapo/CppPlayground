#ifndef ArgumentList_h__
#define ArgumentList_h__

#include <list>

#include "Argument.h"

using namespace std;

class ArgumentList
{
private:
        list<Argument> arguments;

public:
	ArgumentList(list<Argument> args);
	virtual ~ArgumentList();

	const list<Argument> getArguments() const;
};

#endif // ArgumentList_h__
