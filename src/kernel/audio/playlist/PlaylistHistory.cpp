#include "PlaylistHistory.h"

#include <fstream>

#include "../../converter/Convert.h"
#include "../../utils/FileHelper.h"
#include "../../exception/domain/DomainException.h"
#include "../../exception/domain/GeneralDomainErrorCode.h"
#include "exception/PlaylistErrorCode.h"

PlaylistHistory::PlaylistHistory(string filename)
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
	vector<string> fileContent =
		FileHelper::readLastLines(filename.c_str(), lastLines);

	for (int i = 0; i < fileContent.size(); i++)
	{
		history.push_back(fileContent.at(i));
	}
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
	FileHelper::appendLineFileToFile(filename.c_str(), track);

	_locker.unlock();
}
