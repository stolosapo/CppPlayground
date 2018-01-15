#ifndef IcecastClient_h__
#define IcecastClient_h__

#include "config/IcecastClientConfig.h"
#include "IcecastProtocol.h"
#include "IcecastPlaylist.h"
#include "../kernel/log/ILogService.h"
#include "libshout/LibShout.h"

class IcecastClient
{
private:
	ILogService *logSrv;

	IcecastClientConfig* config;
	IcecastProtocol* protocol;
	LibShout* libShout;
	IcecastPlaylist* playlist;

	void loadConfig();
	void streamAudio();

public:
	IcecastClient(ILogService *logSrv);
	virtual ~IcecastClient();

	void action();

};

#endif // IcecastClient_h__
