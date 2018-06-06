#include "Mp3Id3v1.h"

using namespace std;

Mp3Id3v1::Mp3Id3v1() : Mp3TagParser(MP3, MP3_ID3_V1)
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
	ifile = fopen(filename, "r");

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

	//read The Tag to make sure the audio file is tagged
	string tag = readHeader(ifile);

	if (tag != "TAG")
	{
		correctVersion = false;

		cerr << "Mp3 has no ID3v1 tag" << endl;
		fclose(ifile);
		return;
	}

	readMP3(ifile);

	fclose(ifile);
}

AudioMetadata* Mp3Id3v1::parse(FILE* file)
{
	return readMP3(file);
}

bool Mp3Id3v1::isCorrectVersion(FILE* file)
{
	string tag = readHeader(file);

	return tag == "TAG";
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

	if (filetipe != ".mp3")
	{
		return false;
	}
	
	return true;
}

string Mp3Id3v1::readHeader(FILE *file)
{
	//Checks for ID3v1 Tag Header 4bytes long...
	//currently only supports v1
	//v1+ coming later

	//Go to byte location of information
	int readloc = getSize(file) - 128;

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

AudioMetadata* Mp3Id3v1::readMP3(FILE *file)
{
	//The following code reads the information for x bytes and then increases the readlocation x spaces
	//so the next information can be read

	int readloc = getSize(file) - 125;
	title = readThirty(file, readloc);
	readloc += 30;

	artist = readThirty(file, readloc);
	readloc += 30;

	album = readThirty(file, readloc);
	readloc += 30;

	year = readYear(file, readloc);
	readloc += 4;

	comments = readThirty(file, readloc);

	return new AudioMetadata(
		getType(), 
		getTagVersion(), 
		title, 
		artist, 
		album, 
		year, 
		comments);
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
