#ifndef IcecastAgentConfig_h__
#define IcecastAgentConfig_h__

#include <string>

#include "../../kernel/tcp/config/TcpServerConfig.h"

using namespace std;

class IcecastAgentConfig : public TcpServerConfig
{
private:
    static Model* factory();

public:
	IcecastAgentConfig();
	virtual ~IcecastAgentConfig();

protected:
	virtual void registerProperties();

};

#endif // IcecastAgentConfig_h__
