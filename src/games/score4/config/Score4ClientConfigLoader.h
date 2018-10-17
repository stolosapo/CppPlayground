#ifndef Score4ClientConfigLoader_h__
#define Score4ClientConfigLoader_h__

#include <string>

#include "Score4ClientConfig.h"
#include "../../../kernel/configuration/ConfigLoader.h"

using namespace std;

class Score4ClientConfigLoader : public ConfigLoader<Score4ClientConfig>
{
public:
	Score4ClientConfigLoader(string filename);
	virtual ~Score4ClientConfigLoader();

};

#endif // Score4ClientConfigLoader_h__
