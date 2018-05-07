#include "PlaylistMetadata.h"

#include "../../converter/Convert.h"
#include "../../exception/domain/DomainException.h"
#include "../../exception/domain/GeneralDomainErrorCode.h"
#include "exception/PlaylistErrorCode.h"

PlaylistMetadata::PlaylistMetadata(Playlist* playlist, AudioTagService* audioService)
	: playlist(playlist), audioService(audioService)
{

}

PlaylistMetadata::~PlaylistMetadata()
{
	clear();
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

	if (exist(track))
	{
		remove(track);
	}

	metadata[track] = audioTag;
}

void PlaylistMetadata::remove(string track)
{
	metadata.erase(metadata.find(track));
}

void PlaylistMetadata::clear()
{
	/* Clear metadata */
	for (map<string, AudioTag*>::iterator it = metadata.begin(); 
		it != metadata.end(); 
		++it)
	{
		delete it->second;
	}

	metadata.clear();
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
