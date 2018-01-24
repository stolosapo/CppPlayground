#include "IcecastPlaylist.h"

#include <fstream>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

#include "../kernel/converter/Convert.h"
#include "../kernel/exception/domain/DomainException.h"
#include "../kernel/exception/domain/GeneralDomainErrorCode.h"

IcecastPlaylist::IcecastPlaylist(ILogService *logSrv, IcecastClientConfig *config) : logSrv(logSrv), config(config)
{
	srand(time(NULL));
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

	string line;

	while (getline(file, line))
	{
		playlist.push_back(line);
	}

	file.close();

	logSrv->info("Playlist: '" + config->getPlaylist() + "' loaded, with '" + Convert<int>::NumberToString(size()) + "' tracks");
}

int IcecastPlaylist::randomLine()
{
	int size = playlist.size();

	return rand() % size;
}

void IcecastPlaylist::addToHistory(int index)
{
	history_index.push_back(index);
}

bool IcecastPlaylist::existsInHistory(int index)
{
	vector<int>::iterator it = find(history_index.begin(), history_index.end(), index);

	return it != history_index.end();
}

bool IcecastPlaylist::hasNext(int current, int count)
{
	if (config->getRepeat())
	{
		return true;
	}

	return count < playlist.size();
}

string IcecastPlaylist::getNext(int& current)
{
	string track;

	if (config->getRandom())
	{
		current = randomLine();
	}

	track = playlist.at(current);

	return track;
}

int IcecastPlaylist::size()
{
	return playlist.size();
}