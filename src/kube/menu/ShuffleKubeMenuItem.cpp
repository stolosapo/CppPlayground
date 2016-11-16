#ifndef ShuffleKubeMenuItem_h__
#define ShuffleKubeMenuItem_h__

#include <string>
#include "../../log/ILogService.h"
#include "../../menu/MenuItem.h"
#include "../KubeLoader.h"
#include "../KubeNavigator.h"
#include "../KubePrinter.h"
#include "../KubeSolver.h"

using namespace std;

class ShuffleKubeMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

public:
	ShuffleKubeMenuItem(ILogService *logSrv)
	{
		this->logSrv = logSrv;

		this->setId(2);

		this->setName("Suffle Kube");
		this->setTitle("Suffle Kube");
	}

	virtual ~ShuffleKubeMenuItem()
	{

	}
	
	virtual void action()
	{
		KubeLoader *loader = new KubeLoader;
		Kube *kube = loader->createNewKube();
		KubeTracer *tracer = new KubeTracer;
		KubeNavigator *nav = new KubeNavigator(kube, tracer);
		KubeSolver *solver = new KubeSolver(nav);
		KubePrinter *printer = new KubePrinter(logSrv, kube);

		nav->setPrinter(printer);
		nav->setPrintMove(true);
		
		printer->printKube();

		solver->shuffle();
		printer->printKube();

		logSrv->printl("Trace: " + tracer->convertToString());
		logSrv->printl("");
	}

};
#endif // ShuffleKubeMenuItem_h__