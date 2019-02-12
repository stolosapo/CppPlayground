#include "FileUtils.h"

#include <errno.h>
#include <fstream>
#include <cstring>

using namespace std;

void createFile(const char* filepath)
{
    ofstream outfile(filepath);
    outfile.close();
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
