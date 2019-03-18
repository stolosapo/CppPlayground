#ifndef FileReader_h__
#define FileReader_h__

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class FileReader 
{
private:
	fstream file;
	
	vector<string> lines;

	const char* filePath;


public:
	FileReader(const char* filePath);
	virtual ~FileReader();

	vector<string> getLines();

	string getFilePath();

	void read();
};

#endif // FileReader_h__