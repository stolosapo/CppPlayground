#ifndef KubeLoader_h__
#define KubeLoader_h__

#include <string>
#include "Kube.h"

using namespace std;

class KubeLoader
{
private:
	void setKubeSide(Kube *kube, int sideIndex, int lineIndex, string line);
	void setKubeSideTiles(KubeSide *side, int sideIndex, int lineIndex, string line);

public:
	KubeLoader();
	virtual ~KubeLoader();

	Kube* load();
};

#endif // KubeLoader_h__