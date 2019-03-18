#include "PlaylistMetadata.h"

#include "../../converter/Convert.h"
#include "../../exception/domain/DomainException.h"
#include "../../exception/domain/GeneralDomainErrorCode.h"
#include "exception/PlaylistErrorCode.h"

PlaylistMetadata::PlaylistMetadata(Playlist* playlist, AudioTagService* audioService)
	: playlist(playlist), audioService(audioService)
{
	_locker.init();
}

PlaylistMetadata::~PlaylistMetadata()
{
	clear();

	_locker.destroy();
}

void PlaylistMetadata::loadAll()
{
	for (int i = 0; i < playlist->size(); ++i)
	{
		load(playlist->read(i));
	}
}

void PlaylistMetadata::load(string track)
{
	AudioTag* audioTag = audioService->read(track.c_str());

	if (audioTag == NULL)
	{
		throw DomainException(PlaylistErrorCode::PLS0005, track.c_str());
	}

	_locker.lock();

	metadata[track] = audioTag;

	_locker.unlock();
}

void PlaylistMetadata::remove(string track)
{
	_locker.lock();

	metadata.erase(metadata.find(track));

	_locker.unlock();
}

void PlaylistMetadata::clear()
{
	_locker.lock();

	/* Clear metadata */
	for (map<string, AudioTag*>::iterator it = metadata.begin();
		it != metadata.end();
		++it)
	{
		delete it->second;
	}

	metadata.clear();

	_locker.unlock();
}

void PlaylistMetadata::reload()
{
	clear();

	loadAll();
}

bool PlaylistMetadata::exist(string track)
{
	map<string, AudioTag*>::iterator it;
	it = metadata.find(track);

	return it != metadata.end();
}

AudioTag* PlaylistMetadata::read(string track)
{
	if (!exist(track))
	{
		throw DomainException(PlaylistErrorCode::PLS0004, track.c_str());
	}

	return metadata.find(track)->second;
}

AudioTag* PlaylistMetadata::readAndLoadIfNotExist(string track)
{
	if (!exist(track))
	{
		load(track);
	}

	return read(track);
}
