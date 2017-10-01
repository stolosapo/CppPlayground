#include "Mp3Parser.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

/*
	http://www.cplusplus.com/forum/general/105054/
*/


Mp3Parser::Mp3Parser()
{

}

Mp3Parser::~Mp3Parser()
{

}

void Mp3Parser::parse()
{
	const char* filename = "03-TakeFive.mp3";

	ifstream mp3file(filename, ios::binary);
}