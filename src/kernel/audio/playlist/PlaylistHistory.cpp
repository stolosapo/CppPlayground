#include "PlaylistHistory.h"

#include <fstream>

#include "../../converter/Convert.h"
#include "../../exception/domain/DomainException.h"
#include "../../exception/domain/GeneralDomainErrorCode.h"
#include "exception/PlaylistErrorCode.h"

PlaylistHistory::PlaylistHistory(const char* filename)
	: filename(filename)
{
	_locker.init();
}

PlaylistHistory::~PlaylistHistory()
{
	clear();

	_locker.destroy();
}

int PlaylistHistory::size()
{
	return history.size();
}

void PlaylistHistory::loadAll()
{
	load(100);
}

void PlaylistHistory::load(int lastLines)
{

}

void PlaylistHistory::clear()
{
	_locker.lock();

	history.clear();

	_locker.unlock();
}

void PlaylistHistory::reloadAll()
{
	reload(100);
}

void PlaylistHistory::reload(int lastLines)
{
	clear();

	load(lastLines);
}

string PlaylistHistory::read(int historyIndex)
{
	if (historyIndex >= size() || historyIndex < 0)
	{
		throw DomainException(PlaylistErrorCode::PLS0002, Convert<int>::NumberToString(historyIndex).c_str());
	}

	return history[historyIndex];
}

void PlaylistHistory::add(string track)
{
	_locker.lock();

	history.push_back(track);

	_locker.unlock();
}
