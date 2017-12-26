#include <iostream>
#include <string>

#include "../../kernel/utils/FigletHeader.h"

using namespace std;

class GpioMenuItemHeader : public FigletHeader
{
public:
	GpioMenuItemHeader() : FigletHeader()
	{

	}

	virtual ~GpioMenuItemHeader()
	{

	}

private:
	string banner()
	{
		return "\n"
			" #####  ######  ### ####### \n"
			"#     # #     #  #  #     # \n"
			"#       #     #  #  #     # \n"
			"#  #### ######   #  #     # \n"
			"#     # #        #  #     # \n"
			"#     # #        #  #     # \n"
			" #####  #       ### ####### \n";
	}

	string banner3D()
	{
		return "\n"
			":'######:::'########::'####::'#######:: \n"
			"'##... ##:: ##.... ##:. ##::'##.... ##: \n"
			" ##:::..::: ##:::: ##:: ##:: ##:::: ##: \n"
			" ##::'####: ########::: ##:: ##:::: ##: \n"
			" ##::: ##:: ##.....:::: ##:: ##:::: ##: \n"
			" ##::: ##:: ##::::::::: ##:: ##:::: ##: \n"
			". ######::: ##::::::::'####:. #######:: \n"
			":......::::..:::::::::....:::.......::: \n";
	}

	string coinstak()
	{
		return "\n"
			"   O))))    O)))))))   O))     O))))     \n"
			" O)    O))  O))    O)) O))   O))    O))  \n"
			"O))         O))    O)) O)) O))        O))\n"
			"O))         O)))))))   O)) O))        O))\n"
			"O))   O)))) O))        O)) O))        O))\n"
			" O))    O)  O))        O))   O))     O)) \n"
			"  O)))))    O))        O))     O))))     \n";

	}

protected:
	virtual void fillHeaders()
	{
		headers.push_back(banner());
		headers.push_back(banner3D());
		headers.push_back(coinstak());
	}

};
