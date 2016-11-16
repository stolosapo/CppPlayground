#include "KubeColorMapper.h"
#include "../../shared/Colors.h"

using namespace std;


KubeColorMapper::KubeColorMapper()
{

}

KubeColorMapper::~KubeColorMapper()
{

}


char KubeColorMapper::getColorChar()
{
	return colorChar;
}

KubeSide::Color KubeColorMapper::getSideColor()
{
	return sideColor;
}

string KubeColorMapper::getColorCode()
{
	return colorCode;
}

KubeColorMapper* KubeColorMapper::mapColor(char colorChar, int colorIndex)
{
	KubeColorMapper *mapper = new KubeColorMapper;
	mapper->colorChar = colorChar;
	mapper->sideColor = convert(colorIndex);

	switch (colorChar)
	{
		case 'W':
			mapper->colorCode = BOLDWHITE;
			break;

		case 'G':
			mapper->colorCode = BOLDGREEN;
			break;

		case 'B':
			mapper->colorCode = BOLDBLUE;
			break;

		case 'O':
			mapper->colorCode = BOLDMAGENTA;
			break;

		case 'Y':
			mapper->colorCode = BOLDYELLOW;
			break;

		case 'R':
			mapper->colorCode = BOLDRED;
			break;
	}

	return mapper;
}

KubeSide::Color KubeColorMapper::convert(int colorIndex)
{
	return static_cast<KubeSide::Color>(colorIndex);
}

int KubeColorMapper::convert(KubeSide::Color color)
{
	return static_cast<int>(color);
}