#include <iostream>
#include <exception>

#include "kernel/di/GlobalAppContext.h"
#include "kernel/arguments/ArgumentService.h"

#include "kernel/exception/ExceptionMapper.h"

#include "menu/MainMenu.h"

using namespace std;

int main(int argc, char* argv[])
{
	try
	{
		/* Initialize AppContext */
		initializeAppContext(argc, argv);


        ArgumentService* argSrv = inject<ArgumentService>("argService");

		MainMenu menu(argSrv);
		menu.check();
		menu.action();


		/* Clear AppContext */
		deleteAppContext();
	}
    catch(DomainException& e)
	{
        cerr << "Fatal Error: " << handle(e) << endl;
	}
	catch(RuntimeException& e)
	{
        cerr << "Fatal Error: " << handle(e) << endl;
	}
	catch(exception& e)
	{
		cerr << "Fatal Error: " << e.what() << endl;
	}

	cout << endl;
	cout << "Bye Bye.." << endl;
}
