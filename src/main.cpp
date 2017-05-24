#include <iostream>
#include "menu/MainMenu.cpp"
#include "arguments/ArgParser.h"

using namespace std;

int main(int argc, char* argv[])
{
	ArgParser *args = new ArgParser(argc, argv);
	args->printArgs();
	args->parse();
	args->printParsed();

	MainMenu *menu = new MainMenu;
	menu->action();
}