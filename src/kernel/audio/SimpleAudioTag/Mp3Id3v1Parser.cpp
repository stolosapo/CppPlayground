#include "Mp3Id3v1Parser.h"
#include "../../converter/Convert.h"

using namespace std;

Mp3Id3v1Parser::Mp3Id3v1Parser() : AudioTagParser()
{

}

Mp3Id3v1Parser::~Mp3Id3v1Parser()
{

}

bool Mp3Id3v1Parser::isCorrectVersion(FILE* file)
{
	string tag = readHeader(file);

	return tag == "TAG";
}

int Mp3Id3v1Parser::getSize(FILE *file)
{
	//returns the size of the file as an int

	int loc = ftell(file);
	fseek(file,0,SEEK_END);
	int size = ftell(file);
	fseek(file, loc, SEEK_SET);
	return size;
}

bool Mp3Id3v1Parser::checkMp3(string filename)
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

string Mp3Id3v1Parser::readHeader(FILE *file)
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

string Mp3Id3v1Parser::readYear(FILE *file, int readloc)
{
	//Reads Year Of Track...4bytes long

	char magic[4];
	fseek(file , readloc, SEEK_SET);
	fread(magic, 1, 4, file);
	string str(magic);
	return str;
}

string Mp3Id3v1Parser::readThirty(FILE *file, int readloc)
{
	//Used to read Title, Artist, Album, Comment
	//Each is 30 bytes long

	char magic[30];
	fseek(file , readloc, SEEK_SET);
	fread(magic, 1, 30, file);
	string str(magic);
	return str;
}

AudioTag* Mp3Id3v1Parser::parse(FILE *file)
{
	string title = "";
	string artist = "";
	string album = "";
	string comments = "";
	string genre = "";
	string year = 0;

	int track = 0;

	int duration = 0;
	int bitrate = 0;
	int samplerate = 0;
	int channels = 0;

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

	return new AudioTag(title,
			artist,
			album,
			comments,
			genre,
			Convert<int>::StringToNumber(year),
			track,
			duration,
			bitrate,
			samplerate,
			channels);
}
