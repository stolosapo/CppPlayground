#include <iostream>
#include <exception>

#include "lib/di/GlobalAppContext.h"

#include "menu/MainMenu.cpp"
#include "arguments/ArgParser.h"

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
