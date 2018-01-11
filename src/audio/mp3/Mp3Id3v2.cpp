#include "Mp3Id3v2.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int getSize(FILE *file);
string readSize(FILE *file, int readloc, const int sizeToRead);
string header(FILE *file, int readloc);

Mp3Id3v2::Mp3Id3v2()
{

}

Mp3Id3v2::~Mp3Id3v2()
{

}

void Mp3Id3v2::action()
{
        FILE *ifile;
        // ifile = fopen("03-TakeFive.mp3", "r+");
        ifile = fopen("03-Tortoise-Cobwebbed.mp3", "r");

        if (ifile == NULL)
        {
                cerr << "File is null" << endl;
                return;
        }


        int filesize = getSize(ifile);//stores the full file size needed for writing data later
        cout << "Filesize: " << filesize << endl;

        int readloc = 0; //Go to byte location of information
        string tag = header(ifile, readloc); //read The Tag to make sure the audio file is tagged
        cout << "Tag: " << tag << endl;
}

int getSize(FILE *file)
{
	//returns the size of the file as an int
	int loc = ftell(file);
	fseek(file,0,SEEK_END);
	int size = ftell(file);
	fseek(file, loc, SEEK_SET);
	return size;
}

string header(FILE *file, int readloc)
{
	//Checks for ID3v2 Tag Header 10bytes long...

	char magic[10];
	fseek(file , readloc, SEEK_SET);
	fread(magic, 1, 10, file);
	string str(magic);

	string identifier = str.substr(0,3);
        cout << "ID3v2/file identifier: " << identifier << endl;

	string mag = str;
	return mag;
}

string readSize(FILE *file, int readloc, const int sizeToRead)
{
	//Used to read Title, Artist, Album, Comment
	//Each is 30 bytes long
	char magic[sizeToRead];
	fseek(file , readloc, SEEK_SET);
	fread(magic, 1, sizeToRead, file);
	string str(magic);
	return str;
}
