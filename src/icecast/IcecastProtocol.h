#ifndef IcecastProtocol_h__
#define IcecastProtocol_h__

#include <string>

#include "config/IcecastClientConfig.h"

using namespace std;

class IcecastProtocol
{
private:
	static const char* NEW_LINE;

	static const char* USER_AGENT;
	static const char* CONTENT_TYPE;

	IcecastClientConfig* config;

public:
	IcecastProtocol(IcecastClientConfig *config);
	virtual ~IcecastProtocol();

	string connectionRequest();

	string changeMetadataRequest(string newTitle);

	string validateResponse(string responce);

};

#endif // IcecastProtocol_h__
