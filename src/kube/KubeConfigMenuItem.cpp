#include "KubeConfigMenuItem.h"

KubeConfigMenuItem::KubeConfigMenuItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(1);

	this->setName("Configuration");
	this->setTitle("Configuration");
}

KubeConfigMenuItem::~KubeConfigMenuItem()
{
	
}

void KubeConfigMenuItem::action()
{

}