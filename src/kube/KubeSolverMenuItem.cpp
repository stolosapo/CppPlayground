#include "KubeSolverMenuItem.h"

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

}