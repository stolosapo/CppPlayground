#ifndef PlaylistItemModel_h__
#define PlaylistItemModel_h__

#include <string>

#include "PlaylistItem.h"
#include "../../data_model/Model.h"

using namespace std;

class PlaylistItemModel : public Model
{
public:
        PlaylistItemModel();
	PlaylistItemModel(PlaylistItem item);
	virtual ~PlaylistItemModel();

        static Model* factory();

	int getTrackIndex();
	string getTrack();
	string getTrackTitle();
	AudioTag* getMetadata();

protected:
        virtual void registerProperties();

};

#endif // PlaylistItemModel_h__
