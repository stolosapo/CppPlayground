#include <iostream>
#include <string>
#include "../utils/FigletHeader.h"

using namespace std;

class EulerProblemHeader : public FigletHeader
{
public:
	EulerProblemHeader() : FigletHeader()
	{

	}

	virtual ~EulerProblemHeader()
	{

	}

private:
	string isometric()
	{
		return "\n"
			"      ___           ___                         ___           ___     \n"
			"     /\\__\\         /\\  \\                       /\\__\\         /\\  \\    \n"
			"    /:/ _/_        \\:\\  \\                     /:/ _/_       /::\\  \\   \n"
			"   /:/ /\\__\\        \\:\\  \\                   /:/ /\\__\\     /:/\\:\\__\\  \n"
			"  /:/ /:/ _/_   ___  \\:\\  \\   ___     ___   /:/ /:/ _/_   /:/ /:/  /  \n"
			" /:/_/:/ /\\__\\ /\\  \\  \\:\\__\\ /\\  \\   /\\__\\ /:/_/:/ /\\__\\ /:/_/:/__/___\n"
			" \\:\\/:/ /:/  / \\:\\  \\ /:/  / \\:\\  \\ /:/  / \\:\\/:/ /:/  / \\:\\/:::::/  /\n"
			"  \\::/_/:/  /   \\:\\  /:/  /   \\:\\  /:/  /   \\::/_/:/  /   \\::/~~/~~~~ \n"
			"   \\:\\/:/  /     \\:\\/:/  /     \\:\\/:/  /     \\:\\/:/  /     \\:\\~~\\     \n"
			"    \\::/  /       \\::/  /       \\::/  /       \\::/  /       \\:\\__\\    \n"
			"     \\/__/         \\/__/         \\/__/         \\/__/         \\/__/    \n";
	}

protected:
	virtual void fillHeaders()
	{
		headers.push_back(isometric());
	}

};
