#ifndef Score4ClientConfigLoader_h__
#define Score4ClientConfigLoader_h__

#include <string>

#include "Score4ClientConfig.h"
#include "../../../kernel/configuration/IConfigLoader.h"

using namespace std;

class Score4ClientConfigLoader : public IConfigLoader<Score4ClientConfig>
{
public:
	Score4ClientConfigLoader(string filename);
	virtual ~Score4ClientConfigLoader();

	virtual Score4ClientConfig* load();

};

#endif // Score4ClientConfigLoader_h__
