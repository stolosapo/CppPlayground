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

	int getId();
	string getName();
	string getDescription();
	string getHostname();
	int getPort();
	int getPoolsize();

protected:
	virtual void registerProperties();

};

#endif // TcpServerConfig_h__
