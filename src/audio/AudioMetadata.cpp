#include "AudioMetadata.h"

AudioMetadata::AudioMetadata(
	AudioType type, 
	AudioTagVersion tagVersion, 
	string title, 
	string artist, 
	string album, 
	string year, 
	string comments) : 
	type(type), 
	tagVersion(tagVersion), 
	title(title), 
	artist(artist), 
	album(album), 
	year(year), 
	comments(comments)
{

}

AudioMetadata::~AudioMetadata()
{

}

AudioType AudioMetadata::getType()
{
	return type;
}

AudioTagVersion AudioMetadata::getTagVersion()
{
	return tagVersion;
}

string AudioMetadata::getTitle()
{
	return title;
}

string AudioMetadata::getArtist()
{
	return artist;
}

string AudioMetadata::getAlbum()
{
	return album;
}

string AudioMetadata::getYear()
{
	return year;
}

string AudioMetadata::getComments()
{
	return comments;
}
