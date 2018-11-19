#include "MainMenuArgumentAdapter.h"


const string MainMenuArgumentAdapter::TREE = "tree";
const string MainMenuArgumentAdapter::MENU_ITEM = "menuitem";

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
    registerArg(TREE, "Display the complete menu items tree view");
    registerArg(MENU_ITEM, "Specify the menu item name to run directly, bypassing the menu");
}

bool MainMenuArgumentAdapter::hasTreeArg() const
{
    return hasArg(TREE);
}

bool MainMenuArgumentAdapter::hasMenuItem() const
{
    return hasArg(MENU_ITEM);
}

string MainMenuArgumentAdapter::getMenuItem() const
{
    return getStringValue(MENU_ITEM);
}
