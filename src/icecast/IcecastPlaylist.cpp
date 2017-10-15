#include "IcecastPlaylist.h"

#include <fstream>
#include <iterator>
#include <algorithm>
#include <stdlib.h>
#include <time.h>

#include "../lib/converter/Convert.h"
#include "../lib/exception/domain/DomainException.h"
#include "../lib/exception/domain/GeneralDomainErrorCode.h"

IcecastPlaylist::IcecastPlaylist(ILogService *logSrv, IcecastClientConfig *config) : logSrv(logSrv), config(config)
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

	string line;

	while (getline(file, line))
	{
		playlist.push_back(line);
	}

	file.close();

	logSrv->info("Playlist: '" + config->getPlaylist() + "' loaded, with '" + Convert<int>::NumberToString(playlist.size()) + "' tracks");
}

int IcecastPlaylist::randomLine()
{
	srand(time(NULL));

	int size = playlist.size();

	return rand() % size;
}

bool IcecastPlaylist::hasNext(int current)
{
	// if (config->getRepeat())
	// {
	// 	return true;
	// }

	// if (config->getRandom())
	// {
	// 	return true;
	// }

	return current < playlist.size();
}

string IcecastPlaylist::getNext(int& current)
{
	string track;

	// if (config->getRandom())
	// {
	// 	current = randomLine();
	// }

	track = playlist.at(current);

	current++;

	return track;
}