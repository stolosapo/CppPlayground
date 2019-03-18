#include "FileUtils.h"

#include <iostream>
#include <errno.h>
#include <fstream>
#include <cstring>

using namespace std;

void createFile(const char* filepath)
{
    ofstream outfile(filepath);
    outfile.close();
}

bool fileExists(const char* filepath)
{
    ifstream f(filepath);
    return f.good();
}

void addLineToFile(const char* filepath, string line)
{
    ofstream file;

	file.open(filepath, ios::out | ios::app);

	if (file.fail())
	{
		throw ios_base::failure(strerror(errno));
	}

	//make sure write fails with exception if something is wrong
	file.exceptions(file.exceptions() | ios::failbit | ifstream::badbit);

	file << line << endl;

	file.close();
}

vector<string> readLinesFromFile(const char* filepath)
{
    vector<string> output;
    ifstream file(filepath);

    if(file.fail())
    {
        return output;
    }

    string line;
    while (getline(file, line))
    {
        output.push_back(line);
    }

    file.close();

    return output;
}
