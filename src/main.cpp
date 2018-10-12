#include <iostream>
#include <exception>

#include "kernel/di/GlobalAppContext.h"
#include "kernel/arguments/ArgumentService.h"

#include "menu/MainMenu.cpp"

using namespace std;

int main(int argc, char* argv[])
{
	try
	{
		/* Initialize AppContext */
		initializeAppContext(argc, argv);


		MainMenu menu;
		menu.check();
		menu.action();


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
