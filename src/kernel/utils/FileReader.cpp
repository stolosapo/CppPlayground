#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "FileReader.h"

using namespace std;

FileReader::FileReader(const char* filePath)
{
	this->filePath = filePath;

	(this->file).open(this->filePath);
}

FileReader::~FileReader()
{
	(this->file).close();

	vector<string>().swap(this->lines);
}


/* GETTERS */

vector<string> FileReader::getLines()
{
	return this->lines;
}

string FileReader::getFilePath()
{
	return this->filePath;
}




/* METHODS */

void FileReader::read()
{
	string line;

	if (file.is_open())
	{
		while (!file.eof())
		{
			file >> line;

			(this->lines).push_back(line);
		}
	}

	file.close();
}