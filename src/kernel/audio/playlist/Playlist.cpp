#include "Playlist.h"

#include <fstream>

#include "../../converter/Convert.h"
#include "../../exception/domain/DomainException.h"
#include "../../exception/domain/GeneralDomainErrorCode.h"
#include "exception/PlaylistErrorCode.h"

Playlist::Playlist(string filename) : filename(filename)
{
	_locker.init();
}

Playlist::~Playlist()
{
	clear();

	_locker.destroy();
}

string Playlist::itemDescription(int index, string track)
{
    return Convert<int>::NumberToString(index) + ": " + track;
}

int Playlist::size()
{
	return playlist.size();
}

int Playlist::fromWindow(int limit, int offset)
{
    return (limit * offset) - (limit - 1);
}

int Playlist::toWindow(int limit, int offset)
{
    return fromWindow(limit, offset) + (limit - 1);
}

bool Playlist::inSearchWindow(int found_count, int limit, int offset)
{
    int from = fromWindow(limit, offset);
    int to = toWindow(limit, offset);

    return (found_count >= from) && (found_count <= to);
}

bool Playlist::afterSearchWindow(int found_count, int limit, int offset)
{
    return found_count > toWindow(limit, offset);
}

void Playlist::load()
{
	ifstream file(filename.c_str());

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

int Playlist::read(string track)
{
    for (int i = 0; i < size(); i++)
    {
        if (playlist[i] == track)
        {
            return i;
        }
    }

    return -1;
}

vector<string> Playlist::search(string query, int limit, int offset)
{
    vector<string> result;
    int found_count = 0;

    for (size_t i = 0; i < size(); i++)
    {
        string track = playlist.at(i);
        size_t found = track.find(query);

        /* Found */
        if (found != string::npos)
        {
            found_count++;

            if (inSearchWindow(found_count, limit, offset))
            {
                result.push_back(Playlist::itemDescription(i, track));
            }
            else if (afterSearchWindow(found_count, limit, offset))
            {
                break;
            }
        }
    }

    return result;
}
