#include "LogServiceMenuContainer.h"

#include "LogMenuItem.h"

LogServiceMenuContainer::LogServiceMenuContainer() : MenuContainer(
	1,
	"Log Service Test",
	"Log Service Test")
{
	this->setContinueQuestion(true);
}

LogServiceMenuContainer::~LogServiceMenuContainer()
{

}

void LogServiceMenuContainer::fillOptions()
{
	this->addMenuItem(new LogMenuItem(logSrv));
}

string LogServiceMenuContainer::getHeader()
{
	return "";
}
