#ifndef IcecastClientConfigLoader_h__
#define IcecastClientConfigLoader_h__

#include <string>

#include "IcecastClientConfig.h"
#include "../../lib/configuration/IConfigLoader.h"

using namespace std;

class IcecastClientConfigLoader : public IConfigLoader<IcecastClientConfig>
{
public:
	IcecastClientConfigLoader(string filename);
	virtual ~IcecastClientConfigLoader();

	virtual IcecastClientConfig* load();

};

#endif // IcecastClientConfigLoader_h__
