#include "KubeSolverMenuItem.h"
#include "KubeLoader.h"
#include "KubePrinter.h"
#include "KubeColorMapper.h"
#include "KubeNavigator.h"


void makeCross(KubeNavigator *nav, KubePrinter *printer);
void testNotation(KubeNavigator *nav, KubePrinter *printer);


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

	makeCross(nav, printer);
	testNotation(nav, printer);
}




void makeCross(KubeNavigator *nav, KubePrinter *printer)
{
	nav->left();
	nav->left();

	nav->right();
	nav->right();

	nav->front();
	nav->front();

	nav->back();
	nav->back();

	nav->up();
	nav->up();

	nav->down();
	nav->down();

	printer->printKube();
}

void testNotation(KubeNavigator *nav, KubePrinter *printer)
{

	// nav->front();
	// cout << endl << "Move F" << endl << endl;;
	// printer->printKube();

	// nav->aFront();
	// cout << endl << "Move F'" << endl << endl;;
	// printer->printKube();


	// nav->back();
	// cout << endl << "Move B" << endl << endl;;
	// printer->printKube();

	// nav->aBack();
	// cout << endl << "Move B'" << endl << endl;;
	// printer->printKube();



	// nav->up();
	// cout << endl << "Move U" << endl << endl;;
	// printer->printKube();

	// nav->aUp();
	// cout << endl << "Move U'" << endl << endl;;
	// printer->printKube();

	// nav->down();
	// cout << endl << "Move D" << endl << endl;;
	// printer->printKube();

	// nav->aDown();
	// cout << endl << "Move D'" << endl << endl;;
	// printer->printKube();

	// nav->left();
	// cout << endl << "Move L" << endl << endl;;
	// printer->printKube();

	// nav->aLeft();
	// cout << endl << "Move L'" << endl << endl;;
	// printer->printKube();

	// nav->right();
	// cout << endl << "Move R" << endl << endl;;
	// printer->printKube();

	// nav->aRight();
	// cout << endl << "Move R'" << endl << endl;;
	// printer->printKube();



	nav->moveX();
	cout << endl << "Move X" << endl << endl;;
	printer->printKube();

	nav->moveAx();
	cout << endl << "Move X'" << endl << endl;;
	printer->printKube();
}