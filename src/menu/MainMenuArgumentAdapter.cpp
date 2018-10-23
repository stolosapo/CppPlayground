#include "MainMenuArgumentAdapter.h"

MainMenuArgumentAdapter::MainMenuArgumentAdapter(ArgumentService* argService) : ArgumentAdapter(argService)
{

}

MainMenuArgumentAdapter::~MainMenuArgumentAdapter()
{

}

bool MainMenuArgumentAdapter::hasMenuItem() const
{
    return hasArg("menuitem");
}

string MainMenuArgumentAdapter::getMenuItem() const
{
    return getStringValue("menuitem");
}
