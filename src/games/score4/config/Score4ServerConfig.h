#ifndef Score4ServerConfig_h__
#define Score4ServerConfig_h__

#include <string>

#include "../../../kernel/tcp/config/TcpClientConfig.h"

using namespace std;

class Score4ServerConfig : public TcpClientConfig
{
private:
	static Model* factory();
	
public:
	Score4ServerConfig();
	virtual ~Score4ServerConfig();

protected:
	virtual void registerProperties();

};

#endif // Score4ServerConfig_h__
