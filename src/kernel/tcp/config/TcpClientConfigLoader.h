#ifndef TcpClientConfigLoader_h__
#define TcpClientConfigLoader_h__

#include <string>

#include "TcpClientConfig.h"
#include "../../configuration/IConfigLoader.h"

using namespace std;

class TcpClientConfigLoader : public IConfigLoader<TcpClientConfig>
{
public:
	TcpClientConfigLoader(string filename);
	virtual ~TcpClientConfigLoader();

	virtual TcpClientConfig* load();

};

#endif // TcpClientConfigLoader_h__
