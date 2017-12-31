#include "Score4Header.h"

Score4Header::Score4Header() : FigletHeader()
{

}

Score4Header::~Score4Header()
{

}


string Score4Header::standard()
{
	return "\n"                            
		"                        _  _   \n"
		" ___  ___ ___  _ __ ___| || |  \n"
		"/ __|/ __/ _ \\| '__/ _ \\ || |_ \n"
		"\\__ \\ (_| (_) | | |  __/__   _|\n"
		"|___/\\___\\___/|_|  \\___|  |_|  \n"
		"\n";
}

void Score4Header::fillHeaders()
{
	headers.push_back(standard());
}