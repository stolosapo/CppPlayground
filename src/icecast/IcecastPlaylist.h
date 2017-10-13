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

	int randomLine();

public:	
	IcecastPlaylist(IcecastClientConfig *config);
	virtual ~IcecastPlaylist();

	void load();
	bool hasNext(int current);
	string getNext(int& current);

};

#endif // IcecastPlaylist_h__
