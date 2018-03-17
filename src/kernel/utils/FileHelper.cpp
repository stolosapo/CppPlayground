#include "FileHelper.h"

#include "StringHelper.h"

#include <vector>


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

	vector<string> file = StringHelper::split(name, ".");

	if (file.size() != 2)
	{
		return "";
	}

	return file.at(0);
}

string FileHelper::extension(const char* filename)
{
	string name = filenameExt(filename);

	vector<string> file = StringHelper::split(name, ".");

	if (file.size() != 2)
	{
		return "";
	}

	return file.back();
}
