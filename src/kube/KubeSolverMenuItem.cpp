#include "KubeSolverMenuItem.h"
#include "KubeLoader.h"
#include "KubePrinter.h"

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
}