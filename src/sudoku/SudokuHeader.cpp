#include <iostream>
#include <string>
#include "../kernel/utils/FigletHeader.h"

using namespace std;

class SudokuHeader : public FigletHeader
{
public:
	SudokuHeader() : FigletHeader()
	{

	}

	virtual ~SudokuHeader()
	{

	}

private:
	string larry3d()
	{
		return "\n"
			" ____                __          __                \n"
			"/\\  _`\\             /\\ \\        /\\ \\               \n"
			"\\ \\,\\L\\_\\  __  __   \\_\\ \\    ___\\ \\ \\/'\\   __  __  \n"
			" \\/_\\__ \\ /\\ \\/\\ \\  /'_` \\  / __`\\ \\ , <  /\\ \\/\\ \\ \n"
			"   /\\ \\L\\ \\ \\ \\_\\ \\/\\ \\L\\ \\/\\ \\L\\ \\ \\ \\\\`\\\\ \\ \\_\\ \\\n"
			"   \\ `\\____\\ \\____/\\ \\___,_\\ \\____/\\ \\_\\ \\_\\ \\____/\n"
			"    \\/_____/\\/___/  \\/__,_ /\\/___/  \\/_/\\/_/\\/___/ \n";
	}

protected:
	virtual void fillHeaders()
	{
		headers.push_back(larry3d());
	}

};
