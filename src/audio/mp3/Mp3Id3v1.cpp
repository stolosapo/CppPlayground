#include "Mp3Id3v1.h"

using namespace std;

Mp3Id3v1::Mp3Id3v1()
{
	this->title = "";
	this->artist = "";
	this->album = "";
	this->year = "";
	this->comments = "";

	this->correctVersion = true;
}

Mp3Id3v1::~Mp3Id3v1()
{

}

void Mp3Id3v1::load(const char* filename)
{
	FILE *ifile;
	ifile = fopen(filename, "r+");

	if (ifile == NULL)
	{
		cerr << "File is null" << endl;
		fclose(ifile);
		return;
	}

	if (!checkMp3(filename))
	{
		cerr << "File is not Mp3" << endl;
		fclose(ifile);
		return;
	}

	// cout << "File " <<filename<<" Opened Successfully"<<endl;

	//Go to byte location of information
	int readloc = getSize(ifile) - 128;

	//stores the full file size needed for writing data later
	int filesize = getSize(ifile);

	//read The Tag to make sure the audio file is tagged
	string tag = readHeader(ifile, readloc);

	if (tag != "TAG")
	{
		correctVersion = false;

		cerr << "Mp3 has no ID3v1 tag" << endl;
		fclose(ifile);
		return;
	}

	readloc += 3;

	readMP3(ifile);

	fclose(ifile);
}

bool Mp3Id3v1::isCorrectVersion()
{
	return correctVersion;
}

int Mp3Id3v1::getSize(FILE *file)
{
	//returns the size of the file as an int

	int loc = ftell(file);
	fseek(file,0,SEEK_END);
	int size = ftell(file);
	fseek(file, loc, SEEK_SET);
	return size;
}

bool Mp3Id3v1::checkMp3(string filename)
{
	//Checks if the file extension is mp3

	int filetype = filename.length() - 4;
	string filetipe = filename.substr(filetype, 4);
	if (filetipe == ".mp3")
	{
		return true;
	}
	else
	{
		return false;
	}
}

string Mp3Id3v1::readHeader(FILE *file, int readloc)
{
	//Checks for ID3v1 Tag Header 4bytes long...
	//currently only supports v1
	//v1+ coming later

	char magic[4];
	fseek(file , readloc, SEEK_SET);
	fread(magic, 1, 4, file);
	string str(magic);
	string mag = str.substr(0,3);
	return mag;
}

string Mp3Id3v1::readYear(FILE *file, int readloc)
{
	//Reads Year Of Track...4bytes long

	char magic[4];
	fseek(file , readloc, SEEK_SET);
	fread(magic, 1, 4, file);
	string str(magic);
	return str;
}

string Mp3Id3v1::readThirty(FILE *file, int readloc)
{
	//Used to read Title, Artist, Album, Comment
	//Each is 30 bytes long

	char magic[30];
	fseek(file , readloc, SEEK_SET);
	fread(magic, 1, 30, file);
	string str(magic);
	return str;
}

void Mp3Id3v1::readMP3(FILE *file)
{
	//The following code reads the information for x bytes and then increases the readlocation x spaces
	//so the next information can be read

	int readloc = getSize(file)-125;
	title = readThirty(file, readloc);
	readloc+=30;

	artist = readThirty(file, readloc);
	readloc+=30;

	album = readThirty(file, readloc);
	readloc+=30;

	year = readYear(file, readloc);
	readloc+=4;

	comments = readThirty(file, readloc);

	// cout << "Artist: " <<artist<<endl;
	// cout << "Title: " <<title<<endl;
	// cout << "Album: "<<album<<endl;
	// cout << "Year: "<<year<<endl;
	// cout << "Comment: "<<comments<<endl<<endl;
}

string Mp3Id3v1::getTitle()
{
	return title;
}

string Mp3Id3v1::getArtist()
{
	return artist;
}

string Mp3Id3v1::getAlbum()
{
	return album;
}

string Mp3Id3v1::getYear()
{
	return year;
}

string Mp3Id3v1::getComments()
{
	return comments;
}
