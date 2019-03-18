#include <string>
#include "../../kernel/log/ILogService.h"
#include "../../kernel/menu/MenuItem.h"
#include "../action/KubeLoader.h"
#include "../action/KubeNavigator.h"
#include "../action/KubePrinter.h"
#include "../action/KubeSolver.h"

using namespace std;

class SolveKubeMenuItem : public MenuItem
{
private:
	ILogService *logSrv;

public:
	SolveKubeMenuItem(ILogService *logSrv)
	{
		this->logSrv = logSrv;

		this->setId(3);

		this->setName("Solve Kube");
		this->setTitle("Solve Kube");
	}

	virtual ~SolveKubeMenuItem()
	{

	}

	virtual void action()
	{
		KubeLoader *loader = new KubeLoader;
		Kube *kube = loader->load();
		KubePrinter *printer = new KubePrinter(logSrv, kube);
		KubeTracer *tracer = new KubeTracer;
		KubeNavigator *nav = new KubeNavigator(kube, tracer, printer);

		// nav->setPrintMove(true);

		printer->printKube();

		KubeSolver *solver = new KubeSolver(nav);

		solver->solve();

		printer->printKube();


		logSrv->printl("Trace: " + tracer->convertToString());
		logSrv->printl("");
	}

};
