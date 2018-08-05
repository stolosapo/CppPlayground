#include "PlaylistItemModel.h"

#include "../AudioTagModel.h"

PlaylistItemModel::PlaylistItemModel() : Model(&factory)
{
	this->registerProperties();
}

PlaylistItemModel::PlaylistItemModel(PlaylistItem item) : Model(&factory)
{
	this->registerProperties();

	setIntProperty("trackIndex", item.getTrackIndex());
	setStringProperty("track", item.getTrack());
	setObjectProperty("metadata", new AudioTagModel(item.getMetadata()));
}

PlaylistItemModel::~PlaylistItemModel()
{

}

Model* PlaylistItemModel::factory()
{
	return (Model*) new PlaylistItemModel();
}

void PlaylistItemModel::registerProperties()
{
	registerPropertyName(1, "trackIndex", INT);
	registerPropertyName(2, "track", STRING);
	registerPropertyName(3, "metadata", OBJECT, &AudioTagModel::factory);
}
