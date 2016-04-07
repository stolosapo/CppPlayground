#include <iostream>
#include <string>
#include "../utils/FigletHeader.h"

using namespace std;

class KubeHeader : public FigletHeader
{
public:
	KubeHeader() : FigletHeader()
	{

	}

	virtual ~KubeHeader()
	{

	}

private:
	string isometric3()
	{
		return "\n"
			"      ___           ___                         ___     \n"
			"     /__/|         /__/\\         _____         /  /\\    \n"
			"    |  |:|         \\  \\:\\       /  /::\\       /  /:/_   \n"
			"    |  |:|          \\  \\:\\     /  /:/\\:\\     /  /:/ /\\  \n"
			"  __|  |:|      ___  \\  \\:\\   /  /:/~/::\\   /  /:/ /:/_ \n"
			" /__/\\_|:|____ /__/\\  \\__\\:\\ /__/:/ /:/\\:| /__/:/ /:/ /\\\n"
			" \\  \\:\\/:::::/ \\  \\:\\ /  /:/ \\  \\:\\/:/~/:/ \\  \\:\\/:/ /:/\n"
			"  \\  \\::/~~~~   \\  \\:\\  /:/   \\  \\::/ /:/   \\  \\::/ /:/ \n"
			"   \\  \\:\\        \\  \\:\\/:/     \\  \\:\\/:/     \\  \\:\\/:/  \n"
			"    \\  \\:\\        \\  \\::/       \\  \\::/       \\  \\::/   \n"
			"     \\__\\/         \\__\\/         \\__\\/         \\__\\/    \n";
	}

protected:
	virtual void fillHeaders()
	{
		headers.push_back(isometric3());
	}

};
