#ifndef IcecastPlaylist_h__
#define IcecastPlaylist_h__

#include <string>
#include <vector>

#include "config/IcecastClientConfig.h"

using namespace std;

class IcecastPlaylist
{
private:
	IcecastClientConfig* config;

	vector<string> playlist;

public:	
	IcecastPlaylist(IcecastClientConfig *config);
	virtual ~IcecastPlaylist();

	void load();
	bool hasNext();
	string getNext();

};

#endif // IcecastPlaylist_h__
