#include "Mp3MetadataParser.h"

#include <fstream>

#include "../../kernel/exception/domain/DomainException.h"
#include "../../kernel/exception/domain/GeneralDomainErrorCode.h"

#include "Mp3Id3v1.h"

Mp3MetadataParser::Mp3MetadataParser()
{

}

Mp3MetadataParser::~Mp3MetadataParser()
{
	/* Clear parsers*/
	for (vector<Mp3TagParser*>::iterator it = tagParsers.begin();
		it != tagParsers.end(); 
		++it)
	{
		delete *it;
	}

	tagParsers.clear();
}

void Mp3MetadataParser::registerParsers()
{
	tagParsers.push_back(new Mp3Id3v1);
}

bool Mp3MetadataParser::checkMp3(string filename)
{
	//Checks if the file extension is mp3

	int filetype = filename.length() - 4;
	string filetipe = filename.substr(filetype, 4);
	if (filetipe == ".mp3")
	{
		return true;
	}

	return false;
}

AudioMetadata* Mp3MetadataParser::parse(const char* filename)
{
	FILE *file;

	try
	{	
		file = fopen(filename, "r+");

		if (file == NULL || !checkMp3(filename))
		{
			throw DomainException(GeneralDomainErrorCode::GNR0001, filename);
		}

		Mp3TagParser* parser = NULL;

		for(vector<Mp3TagParser*>::iterator it = tagParsers.begin(); 
			it != tagParsers.end(); 
			++it) 
		{
			parser = (Mp3TagParser*) *it;

			if (parser->isCorrectVersion(file))
			{
				break;
			}
		}

		if (parser == NULL)
		{
			return NULL;
		}

		return parser->parse(file);
	}
	catch (exception& e)
	{
		fclose(file);
		throw e;
	}
}