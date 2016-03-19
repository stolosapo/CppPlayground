#include "KubeSolverMenuItem.h"
#include "KubeLoader.h"
#include "KubePrinter.h"
#include "KubeColorMapper.h"
#include "KubeNavigator.h"

KubeSolverMenuItem::KubeSolverMenuItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(2);

	this->setName("The Kube Solution");
	this->setTitle("The Kube Solution");
}

KubeSolverMenuItem::~KubeSolverMenuItem()
{
	
}

void KubeSolverMenuItem::action()
{
	KubeLoader *loader = new KubeLoader;

	Kube *kube;

	kube = loader->load();

	KubePrinter *printer = new KubePrinter(logSrv, kube);

	printer->printKube();

	/* Make some moves */
	KubeNavigator *nav = new KubeNavigator(kube);

	nav->up();
	cout << endl << "Move U" << endl << endl;;
	printer->printKube();

	nav->aUp();
	cout << endl << "Move U'" << endl << endl;;
	printer->printKube();

	nav->down();
	cout << endl << "Move D" << endl << endl;;
	printer->printKube();

	nav->aDown();
	cout << endl << "Move D'" << endl << endl;;
	printer->printKube();

	nav->left();
	cout << endl << "Move L" << endl << endl;;
	printer->printKube();

	nav->aLeft();
	cout << endl << "Move L'" << endl << endl;;
	printer->printKube();

	nav->right();
	cout << endl << "Move R" << endl << endl;;
	printer->printKube();

	nav->aRight();
	cout << endl << "Move R'" << endl << endl;;
	printer->printKube();
}