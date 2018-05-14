#include "Playlist.h"

#include <fstream>

#include "../../converter/Convert.h"
#include "../../exception/domain/DomainException.h"
#include "../../exception/domain/GeneralDomainErrorCode.h"
#include "exception/PlaylistErrorCode.h"

Playlist::Playlist(const char* filename) : filename(filename)
{

}

Playlist::~Playlist()
{
	clear();
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
		playlist.push_back(line);
	}

	file.close();
}

void Playlist::clear()
{
	playlist.clear();
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
