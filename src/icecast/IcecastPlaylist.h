#ifndef IcecastPlaylist_h__
#define IcecastPlaylist_h__

#include <string>
#include <vector>

#include "config/IcecastClientConfig.h"
#include "../kernel/log/ILogService.h"

using namespace std;

class IcecastPlaylist
{
private:
	IcecastClientConfig* config;
	ILogService* logSrv;

	vector<string> playlist;
	vector<int> history_index;

	int randomLine();
	int findNextIndex(int& current);

	void addToHistory(int index);
	bool existsInHistory(int index);

public:
	IcecastPlaylist(ILogService *logSrv, IcecastClientConfig *config);
	virtual ~IcecastPlaylist();

	int size();
	void load();

	bool hasNext(int current, int count);
	string getNext(int& current);

};

#endif // IcecastPlaylist_h__
