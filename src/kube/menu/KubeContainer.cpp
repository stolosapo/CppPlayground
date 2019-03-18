#include <iostream>
#include <string>
#include "../../kernel/menu/MenuContainer.h"
#include "TestKubeNotationMenuItem.h"
#include "ShuffleKubeMenuItem.cpp"
#include "SolveKubeMenuItem.cpp"
#include "KubeHeader.cpp"

using namespace std;

class KubeContainer : public MenuContainer
{
public:
    KubeContainer() : MenuContainer(
        8,
        "The Kube Solver",
        "The Kube Solver")
    {
        this->setContinueQuestion(true);
    }

    virtual ~KubeContainer()
    {

    }

protected:
    virtual void fillOptions()
    {
        this->addMenuItem(new TestKubeNotationMenuItem(logSrv));
        this->addMenuItem(new ShuffleKubeMenuItem(logSrv));
        this->addMenuItem(new SolveKubeMenuItem(logSrv));
    }

    virtual string getHeader()
    {
        KubeHeader header;
        return header.getRandomHeader();
    }

};
