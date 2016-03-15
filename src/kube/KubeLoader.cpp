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

void KubeLoader::mapColor(Kube *kube, int sideIndex, char colorChar)
{
	kube->getColorMapper()[sideIndex] = KubeColorMapper::mapColor(colorChar, sideIndex);
}

void KubeLoader::mapSideColors(Kube *kube, vector<string> lines)
{
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

		if (sideRowIndex == 1)
		{
			char mainColor = line[1];

			mapColor(kube, sideIndex, mainColor);
		}

		sideRowIndex++;
	}
}

void KubeLoader::setKubeSide(Kube *kube, int sideIndex, int lineIndex, string line)
{
	switch (sideIndex)
	{
		case 0:
			kube->setFront(setKubeSideTiles(kube, kube->getFront(), sideIndex, lineIndex, line));
			break;

		case 1:
			kube->setRight(setKubeSideTiles(kube, kube->getRight(), sideIndex, lineIndex, line));
			break;

		case 2:
			kube->setBack(setKubeSideTiles(kube, kube->getBack(), sideIndex, lineIndex, line));
			break;

		case 3:
			kube->setLeft(setKubeSideTiles(kube, kube->getLeft(), sideIndex, lineIndex, line));
			break;

		case 4:
			kube->setUpper(setKubeSideTiles(kube, kube->getUpper(), sideIndex, lineIndex, line));
			break;

		case 5:
			kube->setBottom(setKubeSideTiles(kube, kube->getBottom(), sideIndex, lineIndex, line));
			break;
	}
}

KubeSide* KubeLoader::setKubeSideTiles(Kube *kube, KubeSide *side, int sideIndex, int lineIndex, string line)
{	
	if (side == NULL)
	{
		side = new KubeSide;
	}

	for (int col = 0; col < 3; ++col)
	{
		char colorChar = line[col];

		KubeSide::Color color = kube->getColor(colorChar);

		if (lineIndex == 1)
		{
			side->setMainColor(color);
		}
		
		side->setTile(lineIndex, col, color);
	}

	return side;
}

Kube* KubeLoader::load()
{
	Kube *kube = new Kube;

	string filePath = "kube.txt";
	int index = 0;

	FileReader* reader = new FileReader(filePath.c_str());
	
	reader->read();
	vector<string> lines = reader->getLines();

	/* Map all kube colors */
	mapSideColors(kube, lines);

	/* Load all kube sides */
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

	return kube;
}
