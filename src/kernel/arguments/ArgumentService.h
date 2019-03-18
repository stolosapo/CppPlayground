#ifndef ArgumentService_h__
#define ArgumentService_h__

#include <string>

#include "../service/IService.h"
#include "ArgumentList.h"

using namespace std;

class ArgumentService: public IService
{
private:
    ArgumentList* arguments;

public:
	ArgumentService(int argc, char* argv[]);
	virtual ~ArgumentService();

    bool hasArg(string name) const;
    string getStringValue(string name) const;
    int getIntValue(string name) const;
    bool getBoolValue(string name) const;
};

#endif // ArgumentService_h__
