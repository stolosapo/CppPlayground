#include "SimpleAudioTagService.h"

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>

#include "../../exception/domain/DomainException.h"
#include "../../exception/domain/GeneralDomainErrorCode.h"

#include "Mp3Id3v1Parser.h"

using namespace std;

SimpleAudioTagService::SimpleAudioTagService() : AudioTagService()
{

}

SimpleAudioTagService::~SimpleAudioTagService()
{
        /* Clear parsers*/
        for (vector<AudioTagParser*>::iterator it = tagParsers.begin();
                it != tagParsers.end();
                ++it)
        {
                delete *it;
        }

        tagParsers.clear();
}

void SimpleAudioTagService::registerParsers()
{
	tagParsers.push_back(new Mp3Id3v1Parser);
}

AudioTag* SimpleAudioTagService::read(const char* filename)
{
        FILE *file;

	try
	{
		file = fopen(filename, "r+");

		if (file == NULL)
		{
			throw DomainException(GeneralDomainErrorCode::GNR0001, filename);
		}

		AudioTagParser* parser = NULL;

		for(vector<AudioTagParser*>::iterator it = tagParsers.begin();
			it != tagParsers.end();
			++it)
		{
			parser = (AudioTagParser*) *it;

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
