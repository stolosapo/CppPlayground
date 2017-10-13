#include "IcecastPlaylist.h"

#include <fstream>
#include <iterator>
#include <algorithm>

IcecastPlaylist::IcecastPlaylist(IcecastClientConfig *config) : config(config)
{

}

IcecastPlaylist::~IcecastPlaylist()
{

}

void IcecastPlaylist::load()
{
	ifstream file(config->getPlaylist().c_str());

	copy(istream_iterator<string>(file),
		istream_iterator<string>(),
		back_inserter(playlist));

	file.close();
}

bool IcecastPlaylist::hasNext()
{
	return true;
}

string IcecastPlaylist::getNext()
{
	return playlist.at(0);
}