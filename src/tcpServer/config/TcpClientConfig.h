#ifndef TcpClientConfig_h__
#define TcpClientConfig_h__

#include <string>

#include "../../lib/configuration/IConfig.h"

using namespace std;

class TcpClientConfig : public IConfig
{
public:
	TcpClientConfig();
	virtual ~TcpClientConfig();

	static Model* factory();

	int getId();
	string getName();
	string getDescription();
	string getServerName();
	int getServerPort();

protected:
	virtual void registerProperties();

};

#endif // TcpClientConfig_h__
