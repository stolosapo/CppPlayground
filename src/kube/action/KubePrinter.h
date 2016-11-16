#ifndef KubePrinter_h__
#define KubePrinter_h__

#include "../../log/ILogService.h"
#include "../model/Kube.h"

class KubePrinter
{
private:
	ILogService *logSvc;

	Kube *kube;

	void printKubeRowSide(KubeSide *side, int row);
	void printEmptyKubeRowSpace();

public:
	KubePrinter(ILogService *logSvc, Kube *kube);
	virtual ~KubePrinter();

	void printKube();
};

#endif // KubePrinter_h__