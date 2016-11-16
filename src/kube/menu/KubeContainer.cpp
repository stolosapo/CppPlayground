#include <iostream>
#include <string>
#include "../../shared/Container.h"
#include "TestKubeNotationMenuItem.h"
#include "ShuffleKubeMenuItem.cpp"
#include "SolveKubeMenuItem.cpp"
#include "KubeHeader.cpp"

using namespace std;

class KubeContainer : public Container
{
public:
    KubeContainer() : Container(
        6, 
        "The Kube Solver",
        "The Kube Solver",
        3)
    {
        this->setContinueQuestion(true);
    }

    virtual ~KubeContainer()
    {

    }

protected:
    virtual void fillOptions()
    {
        this->addMenuItem(0, new TestKubeNotationMenuItem(logSrv));
        this->addMenuItem(1, new ShuffleKubeMenuItem(logSrv));
        this->addMenuItem(2, new SolveKubeMenuItem(logSrv));
    }

    virtual string getHeader()
    {
        KubeHeader header;
        return header.getRandomHeader();
    }

};