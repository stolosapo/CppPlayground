#include <iostream>
#include <string>
#include "../../lib/utils/FigletHeader.h"

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

	string _5lineoblique()
	{
		return "\n"
			"    //   / /                           \n"
			"   //__ / /            / __      ___   \n"
			"  //__  /    //   / / //   ) ) //___) )\n"
			" //   \\ \\   //   / / //   / / //       \n"
			"//     \\ \\ ((___( ( ((___/ / ((____    \n";
	}

	string banner4()
	{
		return "\n"
			".##....##.##.....##.########..########\n"
			".##...##..##.....##.##.....##.##......\n"
			".##..##...##.....##.##.....##.##......\n"
			".#####....##.....##.########..######..\n"
			".##..##...##.....##.##.....##.##......\n"
			".##...##..##.....##.##.....##.##......\n"
			".##....##..#######..########..########\n";
	}

	string barbwire()
	{
		return "\n"
			"><<   ><<          ><<                \n"
			"><<  ><<           ><<                \n"
			"><< ><<    ><<  ><<><<         ><<    \n"
			">< ><      ><<  ><<><< ><<   ><   ><< \n"
			"><<  ><<   ><<  ><<><<   ><<><<<<< ><<\n"
			"><<   ><<  ><<  ><<><<   ><<><        \n"
			"><<     ><<  ><<><<><< ><<    ><<<<   \n";
	}

	string basic()
	{
		return "\n"
			"db   dD db    db d8888b. d88888b\n"
			"88 ,8P' 88    88 88  `8D 88'    \n"
			"88,8P   88    88 88oooY' 88ooooo\n"
			"88`8b   88    88 88~~~b. 88~~~~~\n"
			"88 `88. 88b  d88 88   8D 88.    \n"
			"YP   YD ~Y8888P' Y8888P' Y88888P\n";
	}

	string letters()
	{
		return "\n"
			"db   dD db    db d8888b. d88888b\n"
			"88 ,8P' 88    88 88  `8D 88'    \n"
			"88,8P   88    88 88oooY' 88ooooo\n"
			"88`8b   88    88 88~~~b. 88~~~~~\n"
			"88 `88. 88b  d88 88   8D 88.    \n"
			"YP   YD ~Y8888P' Y8888P' Y88888P\n";
	}

	string nipples()
	{
		return "\n"
			"{__   {__          {__                \n"
			"{__  {__           {__                \n"
			"{__ {__    {__  {__{__         {__    \n"
			"{_ {_      {__  {__{__ {__   {_   {__ \n"
			"{__  {__   {__  {__{__   {__{_____ {__\n"
			"{__   {__  {__  {__{__   {__{_        \n"
			"{__     {__  {__{__{__ {__    {____   \n";
	}

protected:
	virtual void fillHeaders()
	{
		headers.push_back(isometric3());
		headers.push_back(_5lineoblique());
		headers.push_back(banner4());
		headers.push_back(barbwire());
		headers.push_back(basic());
		headers.push_back(letters());
		headers.push_back(nipples());
	}

};
