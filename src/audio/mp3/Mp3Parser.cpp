#include "Mp3Parser.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

/*
	http://www.cplusplus.com/forum/general/105054/
*/


const unsigned int Mp3Parser::bitrate[] = { 
	0, 
	32000, 
	40000, 
	48000, 
	56000, 
	64000, 
	80000, 
	96000, 
	112000, 
	128000, 
	60000, 
	192000, 
	224000, 
	256000, 
	320000, 
	0
};

const unsigned int Mp3Parser::freq[] = {
	44100, 
	48000, 
	32000, 
	00000
};


Mp3Parser::Mp3Parser()
{

}

Mp3Parser::~Mp3Parser()
{

}

void Mp3Parser::parse()
{
	const char* filename = "03-TakeFive.mp3";

	ifstream mp3file(filename, ios::binary);

	if(mp3file.fail() == true)
	{
		cout << " *** File failed to open" << endl;
		return;
	}

	cout << " *** File opened" << endl;

	parseDetails(mp3file);
}

void Mp3Parser::parseDetails(ifstream &file)
{
	/* obtain filesize in bits */
	file.seekg(0, ios::end);
	size_t filesize = file.tellg();

	/* create string and allocate correct amount of memory */
	string mp3contents;
    mp3contents.reserve(filesize);

    /* array of characters to transfer binary data prior to copying to string */
    char * buffer;
	buffer = new char [filesize];

	/* transfer binary data from file to buffer array */
	file.seekg(0, ios::beg);
	file.read(buffer, filesize);
	file.close();

	
	int filebitsize = filesize * 8;
	char* bitstorage;
	bitstorage = new char [filebitsize];

	for(unsigned int i = 0; i < filesize; i++)
	{
		for(int k = 0; k < 8; k++)														
		{
			/* convert from bytes to bits */
			bitstorage[(i * 8) + k] = '0' + ((buffer[i] >> k) & 1);
		}
	}

	mp3contents.append(bitstorage);

	/* delete data from dynamically allocated memory */
	delete[] buffer;
	delete[] bitstorage;


	/* vector to store location in string of all frames */
	vector<int> framepositions;

	size_t searchpos = 0;
	string searchterm = "111111111111";
	int j = 0;

	/* while loop to find beginning of all frames in string and store their starting positions in vector */
	while(mp3contents.find(searchterm, searchpos) != -1)
	{
		j++;
		framepositions.push_back(mp3contents.find(searchterm, searchpos));
		searchpos = framepositions[j] + 12;

		cout << " *** Frame " << j << endl;
	}

	/* create substring containing sample rate info in binary */
	string sampleratebinary = mp3contents.substr(framepositions[0] + 21, 2);

	int ongoingtotal = 0;

	/* for loop to find all values of bitrate and add them all together */
	for(unsigned int i = 0; i < framepositions.size(); i++)
	{
		string bitratesubstr = mp3contents.substr(framepositions[i] + 17, 4);
		// ongoingtotal = ongoingtotal + calcbitrate(bitratesubstr);

		cout << " *** Bitrate " << "(" << i << ") :: " << bitratesubstr << endl;
	}

	cout << " *** Ended " << endl;
}