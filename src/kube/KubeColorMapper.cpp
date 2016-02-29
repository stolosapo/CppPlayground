#include "KubeColorMapper.h"
#include "../shared/Colors.h"

using namespace std;


KubeColorMapper::KubeColorMapper()
{

}

KubeColorMapper::~KubeColorMapper()
{

}


KubeColorMapper* KubeColorMapper::mapColor(char colorChar, int colorIndex)
{
	KubeColorMapper *mapper = new KubeColorMapper;
	mapper->colorChar = colorChar;
	mapper->sideColor = convert(colorIndex);

	switch (colorChar)
	{
		case 'W':
			mapper->colorCode = WHITE;
			break;

		case 'G':
			mapper->colorCode = GREEN;
			break;

		case 'B':
			mapper->colorCode = BLUE;
			break;

		case 'O':
			mapper->colorCode = MAGENTA;
			break;

		case 'Y':
			mapper->colorCode = YELLOW;
			break;

		case 'R':
			mapper->colorCode = RED;
			break;

	}

}

KubeSide::Color KubeColorMapper::convert(int colorIndex)
{
	return static_cast<KubeSide::Color>(colorIndex);
}
