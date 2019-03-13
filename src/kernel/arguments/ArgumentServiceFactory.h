#ifndef ArgumentServiceFactory_h__
#define ArgumentServiceFactory_h__

#include <string>

#include "ArgumentService.h"
#include "../service/IServiceFactory.h"
#include "ArgumentList.h"

using namespace std;

class ArgumentServiceFactory: public IServiceFactory
{
private:
    int argc;
    char** argv;

public:
	ArgumentServiceFactory(int argc, char* argv[]);
	virtual ~ArgumentServiceFactory();

    virtual IService* create();
};

#endif // ArgumentServiceFactory_h__
