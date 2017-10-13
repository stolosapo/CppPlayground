#ifndef IcecastProtocol_h__
#define IcecastProtocol_h__

#include <string>

#include "config/IcecastClientConfig.h"

using namespace std;

class IcecastProtocol
{
private:
	static const char* NEW_LINE;

	static const char* CONTENT_TYPE;

	IcecastClientConfig* config;

	string getHttpBasicAuthorization(string user, string password);

public:
	static const char* USER_AGENT;
	
	IcecastProtocol(IcecastClientConfig *config);
	virtual ~IcecastProtocol();

	string connectionRequest();

	string changeMetadataRequest(string newTitle);

	string validateResponse(string responce);

};

#endif // IcecastProtocol_h__
