#include "ArgumentServiceFactory.h"

ArgumentServiceFactory::ArgumentServiceFactory(int argc, char* argv[]) : IServiceFactory(), argc(argc), argv(argv)
{

}

ArgumentServiceFactory::~ArgumentServiceFactory()
{

}

IService* ArgumentServiceFactory::create()
{
    ArgumentService* srv = new ArgumentService(argc, argv);

    return (IService*) srv;
}
