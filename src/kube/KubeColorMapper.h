#ifndef KubeColorMapper_h__
#define KubeColorMapper_h__

#include <string>
#include "KubeSide.h"

using namespace std;

class KubeColorMapper
{
	char colorChar;
	KubeSide::Color sideColor;
	string colorCode;

public:
	KubeColorMapper();
	virtual ~KubeColorMapper();
	
	static KubeColorMapper* mapColor(char colorChar, int colorIndex);
	static KubeSide::Color convert(int colorIndex);
};

#endif // KubeColorMapper_h__