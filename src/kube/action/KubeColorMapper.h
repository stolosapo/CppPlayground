#ifndef KubeColorMapper_h__
#define KubeColorMapper_h__

#include <string>
#include "../model/KubeSide.h"

using namespace std;

class KubeColorMapper
{
private:
	char colorChar;
	KubeSide::Color sideColor;
	string colorCode;

public:
	KubeColorMapper();
	virtual ~KubeColorMapper();

	char getColorChar();
	KubeSide::Color getSideColor();
	string getColorCode();
	
	static KubeColorMapper* mapColor(char colorChar, int colorIndex);
	static KubeSide::Color convert(int colorIndex);
	static int convert(KubeSide::Color color);
};

#endif // KubeColorMapper_h__