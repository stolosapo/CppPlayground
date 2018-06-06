#include "PlaylistStatistics.h"

PlaylistStatistics::PlaylistStatistics()
{
	_locker.init();

	counter = 0;
}

PlaylistStatistics::~PlaylistStatistics()
{
	clear();

	_locker.destroy();
}

void PlaylistStatistics::clear()
{
	_locker.lock();

	genre.clear();
	artist.clear();

	_locker.unlock();
}

void PlaylistStatistics::add(AudioTag* tag)
{
	_locker.lock();

	counter++;

	genre.add(tag->getGenre());
	artist.add(tag->getArtist());

	_locker.unlock();	
}

string PlaylistStatistics::getGenrePercentages()
{
	return genre.getPercentagesAsString(counter);
}

string PlaylistStatistics::getArtistPercentages()
{
	return artist.getPercentagesAsString(counter);
}
