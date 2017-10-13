#include "IcecastPlaylist.h"

#include <fstream>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

#include "../lib/exception/domain/DomainException.h"
#include "../lib/exception/domain/GeneralDomainErrorCode.h"

IcecastPlaylist::IcecastPlaylist(IcecastClientConfig *config) : config(config)
{

}

IcecastPlaylist::~IcecastPlaylist()
{

}

void IcecastPlaylist::load()
{
	ifstream file(config->getPlaylist().c_str());

	if(file.fail() == true)
	{
		throw DomainException(GeneralDomainErrorCode::GNR0001, config->getPlaylist());
	}

	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(playlist));

	file.close();
}

int IcecastPlaylist::randomLine()
{
	srand(time(NULL));

	int size = playlist.size();

	return rand() % size;
}

bool IcecastPlaylist::hasNext(int current)
{
	if (config->getRepeat())
	{
		return true;
	}

	if (config->getRandom())
	{
		return true;
	}

	return current < playlist.size();
}

string IcecastPlaylist::getNext(int& current)
{
	if (config->getRandom())
	{
		current = randomLine();
	}

	if (current < playlist.size())
	{
		current++;
	}
	else if (config->getRepeat())
	{
		current = 0;
	}

	return playlist.at(current);
}