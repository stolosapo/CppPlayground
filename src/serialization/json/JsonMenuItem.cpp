#include "JsonMenuItem.h"
#include "JsonServiceFactory.h"

JsonMenuItem::JsonMenuItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(1);

	this->setName("Test Json Service");
	this->setTitle("Test Json Service");
}

JsonMenuItem::~JsonMenuItem()
{
	
}

void JsonMenuItem::action()
{
	IJsonService *srv = JsonServiceFactory::create();

	srv->test();
}