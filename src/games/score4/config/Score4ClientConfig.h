#ifndef Score4ClientConfig_h__
#define Score4ClientConfig_h__

#include <string>

#include "../../../kernel/tcp/config/TcpClientConfig.h"

using namespace std;

class Score4ClientConfig : public TcpClientConfig
{
private:
	static Model* factory();
	
public:
	Score4ClientConfig();
	virtual ~Score4ClientConfig();

protected:
	virtual void registerProperties();

};

#endif // Score4ClientConfig_h__
