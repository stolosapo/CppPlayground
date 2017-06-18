#ifndef IcecastClientConfig_h__
#define IcecastClientConfig_h__

#include <string>

#include "../../lib/configuration/IConfig.h"

using namespace std;

class IcecastClientConfig : public IConfig
{
public:
	IcecastClientConfig();
	virtual ~IcecastClientConfig();

	static Model* factory();

	string getHostname();
	string getPort();
	string getPassword();
	string getProtocol();
	string getMountpoint();
	string getName();
	string getGenre();
	string getDescription();
	string getUrl();
	string getPublic();
	string getBitrate();
	string getSamplerate();
	string getChannels();

protected:
	virtual void registerProperties();

};

#endif // IcecastClientConfig_h__
