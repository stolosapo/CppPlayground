#include <string>
#include "KubePrinter.h"
#include "KubeColorMapper.h"

using namespace std;

KubePrinter::KubePrinter(ILogService *logSvc, Kube *kube)
{
	this->logSvc = logSvc;
	this->kube = kube;
}

KubePrinter::~KubePrinter()
{

}


void KubePrinter::printKubeRowSide(KubeSide *side, int row)
{
	for (int col = 0; col < 3; ++col)
	{
		KubeSide::Color color = side->getTiles()[row][col];

		int c = KubeColorMapper::convert(color);

		KubeColorMapper *map = kube->getColorMapper()[c];
		
		logSvc->print("[*]", map->getColorCode());
	}
}

void KubePrinter::printEmptyKubeRowSpace()
{
	for (int col = 0; col < 3; ++col)
	{
		cout << "   ";
	}
}

void KubePrinter::printKube()
{
	//1st kube level

	for (int row = 0; row < 3; ++row)
	{
		printEmptyKubeRowSpace();

		printKubeRowSide(kube->getUpper(), row);

		printEmptyKubeRowSpace();

		logSvc->printl("");
	}


	// 2nd kube level

	for (int row = 0; row < 3; ++row)
	{
		printKubeRowSide(kube->getLeft(), row);

		printKubeRowSide(kube->getFront(), row);

		printKubeRowSide(kube->getRight(), row);

		printKubeRowSide(kube->getBack(), row);

		logSvc->printl("");
	}
	

	// 3rd kube level

	for (int row = 0; row < 3; ++row)
	{
		printEmptyKubeRowSpace();

		printKubeRowSide(kube->getBottom(), row);

		logSvc->printl("");
	}

	logSvc->printl("");
}
