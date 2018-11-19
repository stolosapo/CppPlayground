#include "MainMenuArgumentAdapter.h"

MainMenuArgumentAdapter::MainMenuArgumentAdapter(ArgumentService* argService) : ArgumentAdapter(argService)
{

}

MainMenuArgumentAdapter::~MainMenuArgumentAdapter()
{

}

string MainMenuArgumentAdapter::help()
{
    return "";
}

void MainMenuArgumentAdapter::registerArguments()
{

}

bool MainMenuArgumentAdapter::hasTreeArg() const
{
    return hasArg("tree");
}

bool MainMenuArgumentAdapter::hasMenuItem() const
{
    return hasArg("menuitem");
}

string MainMenuArgumentAdapter::getMenuItem() const
{
    return getStringValue("menuitem");
}
