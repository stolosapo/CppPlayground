#ifndef FileHelper_h__
#define FileHelper_h__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class FileHelper
{
public:
	static const char* FILE_DELIMITTER;

	FileHelper();
	virtual ~FileHelper();

    static bool exists(const char* filepath);
	static string filenameExt(const char* filepath);
	static string filename(const char* filepath);
	static string extension(const char* filename);

	static void appendLineFileToFile(const char* filename, string line);
	static vector<string> readLastLines(const char* filename, int lineCount);
};

#endif // FileHelper_h__
