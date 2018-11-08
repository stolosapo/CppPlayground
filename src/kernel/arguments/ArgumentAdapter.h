#ifndef ArgumentAdapter_h__
#define ArgumentAdapter_h__

#include <string>
#include <map>

#include "ArgumentService.h"

using namespace std;

class ArgumentAdapter
{
private:
    ArgumentService* argService;

    map<string, string> registeredArgs;

    bool argExist(const string& name) const;

public:
	ArgumentAdapter(ArgumentService* argService);
	virtual ~ArgumentAdapter();

    virtual string help();

protected:
    virtual string title();
    void registerArg(string name, string description);

    bool hasArg(string name) const;
    string getStringValue(string name) const;
    int getIntValue(string name) const;
    bool getBoolValue(string name) const;

};

#endif // ArgumentAdapter_h__
