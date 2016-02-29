#include "KubePrinter.h"
#include <string>

using namespace std;

KubePrinter::KubePrinter(ILogService *logSvc, Kube *kube)
{
	this->logSvc = logSvc;
	this->kube = kube;
}

KubePrinter::~KubePrinter()
{

}


void KubePrinter::printKubeSide(KubeSide *side)
{
	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 3; ++col)
		{
			KubeSide::Color color = side->getTiles()[row][col];
			int c = static_cast<int>(color);
			
			cout << "[" << c << "]";
		}

		cout << endl;
	}
}

void KubePrinter::printEmptyKubeSpace()
{
	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 3; ++col)
		{
			cout << "   ";
		}

		cout << endl;
	}
}

void KubePrinter::printKube()
{
	//1st kube level

	printEmptyKubeSpace();

	printKubeSide(kube->getUpper());

	printEmptyKubeSpace();

	logSvc->printl("");


	// 2nd kube level

	printKubeSide(kube->getLeft());

	printKubeSide(kube->getFront());

	printKubeSide(kube->getRight());

	printKubeSide(kube->getBack());

	logSvc->printl("");


	// 3rd kube level

	printEmptyKubeSpace();

	printKubeSide(kube->getBottom());

	logSvc->printl("");

}
