#include "Score4MenuContainer.h"
#include "Score4Header.h"
#include "Score4ServerMenuItem.h"
#include "Score4ClientMenuItem.h"

Score4MenuContainer::Score4MenuContainer() : MenuContainer(
	1,
	"Score 4",
	"Score 4",
	2)
{

}

Score4MenuContainer::~Score4MenuContainer()
{

}

void Score4MenuContainer::fillOptions()
{
	this->addMenuItem(0, new Score4ServerMenuItem(logSrv));
	this->addMenuItem(1, new Score4ClientMenuItem(logSrv));
}

string Score4MenuContainer::getHeader()
{
	Score4Header header;
	return header.getRandomHeader();
}
