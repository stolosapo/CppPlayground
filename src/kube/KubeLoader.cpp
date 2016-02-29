#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "KubeLoader.h"
#include "KubeColorMapper.h"

using namespace std;

KubeLoader::KubeLoader()
{

}

KubeLoader::~KubeLoader()
{

}


void KubeLoader::setKubeSide(Kube *kube, int sideIndex, int lineIndex, string line)
{
	switch (sideIndex)
	{
		case 0:
			setKubeSideTiles(kube->getFront(), sideIndex, lineIndex, line);
			break;

		case 1:
			setKubeSideTiles(kube->getRight(), sideIndex, lineIndex, line);
			break;

		case 2:
			setKubeSideTiles(kube->getBack(), sideIndex, lineIndex, line);
			break;

		case 3:
			setKubeSideTiles(kube->getLeft(), sideIndex, lineIndex, line);
			break;

		case 4:
			setKubeSideTiles(kube->getUpper(), sideIndex, lineIndex, line);
			break;

		case 5:
			setKubeSideTiles(kube->getBottom(), sideIndex, lineIndex, line);
			break;
	}
}

void KubeLoader::setKubeSideTiles(KubeSide *side, int sideIndex, int lineIndex, string line)
{	
	if (side == NULL)
	{
		side = new KubeSide;
	}

	for (int col = 0; col < 3; ++col)
	{
		char colorChar = line[col];

		side->setTile(lineIndex, col, KubeColorMapper::convert(sideIndex));
	}
}

Kube* KubeLoader::load()
{
	Kube *kube = new Kube;

	string filePath = "kube.txt";
	// int index = 0;

	// FileReader* reader = new FileReader(filePath.c_str());
	
	// reader->read();
	// vector<string> lines = reader->getLines();


	// int kubeLevel = 0;
	// int sideLevel = 0;

	// KubeSide *side;

	// for (int row = 0; row < lines.size(); ++row)
	// {
	// 	string line = lines[row];

	// 	if (line == "")
	// 	{
	// 		kubeLevel++;
	// 		sideLevel = 0;
	// 		continue;
	// 	}

	// 	if (sideLevel == 0)
	// 	{
	// 		 side = new KubeSide;
	// 	}

		

	// 	for (int col = 0; col < 3; ++col)
	// 	{
	// 		char colorChar = line[col];


	// 	}
	// }

	return kube;
}
