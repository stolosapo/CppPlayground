#ifndef AudioTagModel_h__
#define AudioTagModel_h__

#include <string>

#include "AudioTag.h"
#include "../data_model/Model.h"

using namespace std;

class AudioTagModel : public Model
{
public:
	AudioTagModel();
        AudioTagModel(AudioTag* tag);
	virtual ~AudioTagModel();

        static Model* factory();

	string getTitle();
	string getArtist();
	string getAlbum();
	string getComments();
	string getGenre();
	int getYear();
	int getTrack();

	int getDuration();
	int getBitrate();
	int getSamplerate();
	int getChannels();

protected:
        virtual void registerProperties();
};

#endif // AudioTagModel_h__
