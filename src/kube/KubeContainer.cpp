#include <iostream>
#include <string>
#include "KubeConfigMenuItem.h"
#include "KubeSolverMenuItem.h"
#include "../shared/Container.h"
#include "KubeHeader.cpp"

using namespace std;

class KubeContainer : public Container
{
public:
    KubeContainer() : Container(
        4, 
        "The Kube Solver",
        "The Kube Solver",
        2)
    {
        this->setContinueQuestion(true);
    }

    virtual ~KubeContainer()
    {

    }

protected:
    virtual void fillOptions()
    {
        this->addMenuItem(0, new KubeConfigMenuItem(logSrv));
        this->addMenuItem(1, new KubeSolverMenuItem(logSrv));
    }

    virtual string getHeader()
    {
        KubeHeader header;
        return header.getRandomHeader();
    }

};