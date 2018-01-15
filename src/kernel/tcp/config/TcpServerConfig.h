#ifndef TcpServerConfig_h__
#define TcpServerConfig_h__

#include <string>

#include "../../configuration/IConfig.h"

using namespace std;

class TcpServerConfig : public IConfig
{
private:
	static const int DEFAULT_PORT = 51717;
	static const int DEFAULT_THREAD_POOL_SIZE = 5;
	static const char* DEFAULT_HOSTNAME;

	static Model* factory();

public:
	TcpServerConfig();
	virtual ~TcpServerConfig();

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
