#ifndef PlaylistStatistics_h__
#define PlaylistStatistics_h__

#include <string>
#include <map>

#include "Statistics.h"
#include "../AudioTag.h"
#include "../../task/Locker.h"

using namespace std;

class PlaylistStatistics
{
private:
	Locker _locker;

	int counter;

	Statistics genre;
	Statistics artist;

public:
	PlaylistStatistics();
	virtual ~PlaylistStatistics();

	void clear();

	void add(AudioTag* tag);

	string getGenrePercentages();
	string getArtistPercentages();

};

#endif // PlaylistStatistics_h__
