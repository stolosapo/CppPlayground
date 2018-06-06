#include "GameMenuContainer.h"
#include "GameHeader.h"

#include "score4/menu/Score4MenuContainer.h"

GameMenuContainer::GameMenuContainer() : MenuContainer(
	7,
	"Games",
	"Games",
	1)
{

}

GameMenuContainer::~GameMenuContainer()
{

}

void GameMenuContainer::fillOptions()
{
	this->addMenuItem(0, new Score4MenuContainer);
}

string GameMenuContainer::getHeader()
{
	GameHeader header;
	return header.getRandomHeader();
}
