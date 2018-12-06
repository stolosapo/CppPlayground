#ifndef NoiseStreamerPlaylist_h__
#define NoiseStreamerPlaylist_h__

#include <signal.h>

#include "../../kernel/log/ILogService.h"

using namespace std;

class NoiseStreamerPlaylist
{
private:
    ILogService *logSrv;

protected:

public:
	NoiseStreamerPlaylist(ILogService* logSrv);
	virtual ~NoiseStreamerPlaylist();

};

#endif // NoiseStreamerPlaylist_h__
