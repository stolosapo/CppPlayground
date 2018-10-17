#ifndef Score4ServerConfigLoader_h__
#define Score4ServerConfigLoader_h__

#include <string>

#include "Score4ServerConfig.h"
#include "../../../kernel/configuration/ConfigLoader.h"

using namespace std;

class Score4ServerConfigLoader : public ConfigLoader<Score4ServerConfig>
{
public:
	Score4ServerConfigLoader(string filename);
	virtual ~Score4ServerConfigLoader();

};

#endif // Score4ServerConfigLoader_h__
