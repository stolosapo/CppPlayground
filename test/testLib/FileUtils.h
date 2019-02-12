#ifndef FileUtils_h__
#define FileUtils_h__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void createFile(const char* filepath);
bool fileExists(const char* filepath);
void addLineToFile(const char* filepath, string line);
vector<string> readLinesFromFile(const char* filepath);

#endif // FileUtils_h__
