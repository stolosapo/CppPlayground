#include "MainMenuArgumentAdapter.h"


const string MainMenuArgumentAdapter::HELP = "help";
const string MainMenuArgumentAdapter::TREE = "tree";
const string MainMenuArgumentAdapter::MENU_ITEM = "menuitem";

MainMenuArgumentAdapter::MainMenuArgumentAdapter(ArgumentService* argService) : ArgumentAdapter(argService)
{

}

MainMenuArgumentAdapter::~MainMenuArgumentAdapter()
{

}

string MainMenuArgumentAdapter::title()
{
    return "MainMenu";
}

void MainMenuArgumentAdapter::registerArguments()
{
    registerArg(HELP, "Help...");
    registerArg(TREE, "Display the complete menu items tree view");
    registerArg(MENU_ITEM, "Specify the menu item name to run directly, bypassing the menu");
}

bool MainMenuArgumentAdapter::hasHelpArg() const
{
    return hasArg(HELP);
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
