#include "Playlist.h"

#include <fstream>

#include "../../converter/Convert.h"
#include "../../exception/domain/DomainException.h"
#include "../../exception/domain/GeneralDomainErrorCode.h"
#include "exception/PlaylistErrorCode.h"

Playlist::Playlist(const char* filename) : filename(filename)
{
	_locker.init();
}

Playlist::~Playlist()
{
	clear();

	_locker.destroy();
}

int Playlist::size()
{
	return playlist.size();
}

void Playlist::load()
{
	ifstream file(filename);

	if(file.fail())
	{
		throw DomainException(GeneralDomainErrorCode::GNR0001, filename);
	}

	string line;

	while (getline(file, line))
	{
		_locker.lock();
		
		playlist.push_back(line);

		_locker.unlock();
	}

	file.close();
}

void Playlist::clear()
{
	_locker.lock();

	playlist.clear();

	_locker.unlock();
}

void Playlist::reload()
{
	clear();

	load();
}

string Playlist::read(int trackIndex)
{
	if (trackIndex >= size() || trackIndex < 0)
	{
		throw DomainException(PlaylistErrorCode::PLS0001, Convert<int>::NumberToString(trackIndex).c_str());
	}

	return playlist[trackIndex];
}
