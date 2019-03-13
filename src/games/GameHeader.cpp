#include "GameHeader.h"

GameHeader::GameHeader() : FigletHeader()
{

}

GameHeader::~GameHeader()
{

}


string GameHeader::standard()
{
	return "\n"                            
		"  __ _  __ _ _ __ ___   ___  ___ \n"
		" / _` |/ _` | '_ ` _ \\ / _ \\/ __|\n"
		"| (_| | (_| | | | | | |  __/\\__ \\\n"
		" \\__, |\\__,_|_| |_| |_|\\___||___/\n"
		" |___/                           \n"
		"\n";
}

void GameHeader::fillHeaders()
{
	headers.push_back(standard());
}