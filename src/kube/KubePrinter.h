#ifndef KubePrinter_h__
#define KubePrinter_h__

#include "../log/ILogService.h"
#include "Kube.h"

class KubePrinter
{
private:
	ILogService *logSvc;

	Kube *kube;

	void printKubeSide(KubeSide *side);
	void printEmptyKubeSpace();

public:
	KubePrinter(ILogService *logSvc, Kube *kube);
	virtual ~KubePrinter();

	void printKube();
};

#endif // KubePrinter_h__