#ifndef NoiseStreamerAgentConfig_h__
#define NoiseStreamerAgentConfig_h__

#include <string>

#include "../../kernel/tcp/config/TcpServerConfig.h"

using namespace std;

class NoiseStreamerAgentConfig : public TcpServerConfig
{
private:
    static Model* factory();

public:
	NoiseStreamerAgentConfig();
	virtual ~NoiseStreamerAgentConfig();

    string getIcecastConfig();

protected:
	virtual void registerProperties();

};

#endif // NoiseStreamerAgentConfig_h__
