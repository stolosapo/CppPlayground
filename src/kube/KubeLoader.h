#ifndef KubeLoader_h__
#define KubeLoader_h__

#include <string>
#include <vector>
#include "Kube.h"
#include "KubeColorMapper.h"

using namespace std;

class KubeLoader
{
private:
	void mapColor(Kube *kube, int sideIndex, char colorChar);
	void mapSideColors(Kube *kube, vector<string> lines);

	void setKubeSide(Kube *kube, int sideIndex, int lineIndex, string line);
	KubeSide* setKubeSideTiles(Kube *kube, KubeSide *side, int sideIndex, int lineIndex, string line);

public:
	KubeLoader();
	virtual ~KubeLoader();

	Kube* load();
};

#endif // KubeLoader_h__