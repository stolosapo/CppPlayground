#ifndef FileHelper_h__
#define FileHelper_h__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class FileHelper
{
private:
    static FILE* openFile(string filename, const char* mode);

public:
	static const char* FILE_DELIMITTER;

	FileHelper();
	virtual ~FileHelper();

    static FILE* openReadBinary(string filename);
    static FILE* openWriteBinary(string filename);

    static void createFile(string filename);

    static bool exists(const char* filepath);
	static string filenameExt(const char* filepath);
	static string filename(const char* filepath);
	static string extension(const char* filename);

	static void appendLineFileToFile(const char* filename, string line);
	static vector<string> readLastLines(const char* filename, int lineCount);
};

#endif // FileHelper_h__
