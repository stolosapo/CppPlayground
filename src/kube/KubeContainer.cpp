#include <iostream>
#include <string>
#include "TestKubeNotationMenuItem.h"
#include "../shared/Container.h"
#include "KubeHeader.cpp"

using namespace std;

class KubeContainer : public Container
{
public:
    KubeContainer() : Container(
        6, 
        "The Kube Solver",
        "The Kube Solver",
        1)
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
    }

    virtual string getHeader()
    {
        KubeHeader header;
        return header.getRandomHeader();
    }

};