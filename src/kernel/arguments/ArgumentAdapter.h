#ifndef ArgumentAdapter_h__
#define ArgumentAdapter_h__

#include <string>

#include "ArgumentService.h"

using namespace std;

class ArgumentAdapter
{
private:
    ArgumentService* argService;

public:
	ArgumentAdapter(ArgumentService* argService);
	virtual ~ArgumentAdapter();

protected:
    bool hasArg(string name) const;
    string getStringValue(string name) const;
    int getIntValue(string name) const;
    bool getBoolValue(string name) const;

};

#endif // ArgumentAdapter_h__
