#ifndef Score4ServerConfigLoader_h__
#define Score4ServerConfigLoader_h__

#include <string>

#include "Score4ServerConfig.h"
#include "../../../kernel/configuration/IConfigLoader.h"

using namespace std;

class Score4ServerConfigLoader : public IConfigLoader<Score4ServerConfig>
{
public:
	Score4ServerConfigLoader(string filename);
	virtual ~Score4ServerConfigLoader();

	virtual Score4ServerConfig* load();

};

#endif // Score4ServerConfigLoader_h__
