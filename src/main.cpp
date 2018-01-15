#include <iostream>
#include <exception>

#include "kernel/di/GlobalAppContext.h"
#include "kernel/arguments/ArgParser.h"

#include "menu/MainMenu.cpp"

using namespace std;

int main(int argc, char* argv[])
{
	try
	{
		/* Initialize AppContext */
		initializeAppContext();


		ArgParser *args = new ArgParser(argc, argv);
		args->printArgs();
		args->parse();
		args->printParsed();

		MainMenu *menu = new MainMenu;
		menu->check();
		menu->action();


		/* Clear AppContext */
		deleteAppContext();
	}
	catch(exception& e)
	{
		cerr << "Fatal Error: " << e.what() << endl;
	}

	cout << endl;
	cout << "Bye Bye.." << endl;
}
