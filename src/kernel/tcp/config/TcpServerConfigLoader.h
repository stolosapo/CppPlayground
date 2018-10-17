#ifndef TcpServerConfigLoader_h__
#define TcpServerConfigLoader_h__

#include <string>

#include "TcpServerConfig.h"
#include "../../configuration/IConfigLoader.h"

using namespace std;

class TcpServerConfigLoader : public IConfigLoader<TcpServerConfig>
{
public:
	TcpServerConfigLoader(string filename);
	virtual ~TcpServerConfigLoader();

    virtual TcpServerConfig* createNewConfigInstance();

};

#endif // TcpServerConfigLoader_h__
