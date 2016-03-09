#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "KubeLoader.h"
#include "KubeColorMapper.h"
#include "../shared/FileReader.h"

using namespace std;

KubeLoader::KubeLoader()
{

}

KubeLoader::~KubeLoader()
{

}


void KubeLoader::setKubeSide(Kube *kube, int sideIndex, int lineIndex, string line)
{
	KubeSide *side;

	switch (sideIndex)
	{
		case 0:
			side = kube->getFront();
			break;

		case 1:
			side = kube->getRight();
			break;

		case 2:
			side = kube->getBack();
			break;

		case 3:
			side = kube->getLeft();
			break;

		case 4:
			side = kube->getUpper();
			break;

		case 5:
			side = kube->getBottom();
			break;
	}

	setKubeSideTiles(side, sideIndex, lineIndex, line);
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
	int index = 0;

	FileReader* reader = new FileReader(filePath.c_str());
	
	reader->read();
	vector<string> lines = reader->getLines();

	int sideIndex = 0;
	int sideRowIndex = 0;

	for (int row = 0; row < lines.size(); ++row)
	{
		string line = lines[row];

		if (line == "---")
		{
			sideIndex++;
			sideRowIndex = 0;
			continue;
		}

		setKubeSide(kube, sideIndex, sideRowIndex, line);

		sideRowIndex++;
	}

	if (kube->getUpper() == NULL)
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << "full" << endl;
	}

	return kube;
}
