#include "FileHelper.h"

#include "StringHelper.h"

#include <errno.h>
#include <fstream>
#include <cstring>

#include "../exception/domain/DomainException.h"
#include "../exception/domain/GeneralDomainErrorCode.h"

using namespace std;

const char* FileHelper::FILE_DELIMITTER = "/";

FileHelper::FileHelper()
{

}

FileHelper::~FileHelper()
{

}

string FileHelper::filenameExt(const char* filepath)
{
	vector<string> directories = StringHelper::split(string(filepath), string(FILE_DELIMITTER));

	return directories.back();
}

string FileHelper::filename(const char* filepath)
{
	string name = filenameExt(filepath);

	string ext = extension(name.c_str());

	if (ext == "")
	{
		return name;
	}

	ext = "." + ext;

	size_t pos = name.find(ext);

	return name.substr(0, pos);
}

string FileHelper::extension(const char* filename)
{
	string name = filenameExt(filename);

	vector<string> file = StringHelper::split(name, ".");

	if (file.size() <= 1)
	{
		return "";
	}

	return file.back();
}

void FileHelper::appendLineFileToFile(const char* filename, string line)
{
	ofstream file;

	file.open(filename, ios::out | ios::app);

	if (file.fail())
	{
		throw ios_base::failure(strerror(errno));
	}

	//make sure write fails with exception if something is wrong
	file.exceptions(file.exceptions() | ios::failbit | ifstream::badbit);

	file << line << endl;

	file.close();
}

vector<string> FileHelper::readLastLines(const char* filename, int lineCount)
{
	ifstream file(filename);

	if(file.fail())
	{
		throw DomainException(GeneralDomainErrorCode::GNR0001, filename);
	}

	vector<string> fileContent;
	string line;
	while (getline(file, line))
	{
		fileContent.push_back(line);
	}

	file.close();

	int it = 0;
	vector<string> output;
	while (it < lineCount && !fileContent.empty())
	{
		output.insert(output.begin(), fileContent.back());
		fileContent.pop_back();
		it++;
	}

	return output;
}
