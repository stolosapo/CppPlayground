#ifndef TcpServerConfig_h__
#define TcpServerConfig_h__

#include <string>

#include "../../lib/configuration/IConfig.h"

using namespace std;

class TcpServerConfig : public IConfig
{
public:
	TcpServerConfig();
	virtual ~TcpServerConfig();

	static Model* factory();

	int getServerPort();
	string getServerHostname();

protected:
	virtual void registerProperties();

};

#endif // TcpServerConfig_h__