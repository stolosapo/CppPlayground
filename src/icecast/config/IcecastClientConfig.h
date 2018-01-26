#ifndef IcecastClientConfig_h__
#define IcecastClientConfig_h__

#include <string>

#include "../../kernel/configuration/IConfig.h"

using namespace std;

class IcecastClientConfig : public IConfig
{
public:
	IcecastClientConfig();
	virtual ~IcecastClientConfig();

	static Model* factory();

	string getHostname();
	string getPort();
	string getUsername();
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

	string getPlaylist();
	bool getRandom();
	bool getRepeat();

protected:
	virtual void registerProperties();

};

#endif // IcecastClientConfig_h__