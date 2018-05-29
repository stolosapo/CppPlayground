#ifndef FileHelper_h__
#define FileHelper_h__

#include <iostream>
#include <string>

using namespace std;

class FileHelper
{
public:
	static const char* FILE_DELIMITTER;

	FileHelper();
	virtual ~FileHelper();

	static string filenameExt(const char* filepath);
	static string filename(const char* filepath);
	static string extension(const char* filename);

	static void appendLineFileToFile(const char* filename, string line);
};

#endif // FileHelper_h__