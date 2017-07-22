#include <iostream>

#include "lib/di/GlobalAppContext.h"

#include "menu/MainMenu.cpp"
#include "arguments/ArgParser.h"

using namespace std;

int main(int argc, char* argv[])
{
	/* Initialize AppContext */
	initializeAppContext();


	ArgParser *args = new ArgParser(argc, argv);
	args->printArgs();
	args->parse();
	args->printParsed();

	MainMenu *menu = new MainMenu;
	menu->action();


	/* Clear AppContext */
	deleteAppContext();
}