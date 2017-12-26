#ifndef TcpClientConfig_h__
#define TcpClientConfig_h__

#include <string>

#include "../../kernel/configuration/IConfig.h"

using namespace std;

class TcpClientConfig : public IConfig
{
private:
	static const int DEFAULT_PORT = 51717;
	static const char* DEFAULT_SERVERNAME;
	
	static Model* factory();
	
public:
	TcpClientConfig();
	virtual ~TcpClientConfig();


	int getId();
	string getName();
	string getDescription();
	string getServerName();
	int getServerPort();

protected:
	virtual void registerProperties();

};

#endif // TcpClientConfig_h__
