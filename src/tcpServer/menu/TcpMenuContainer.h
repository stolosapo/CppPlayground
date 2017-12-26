#ifndef TcpMenuContainer_h__
#define TcpMenuContainer_h__

#include <iostream>
#include <string>

#include "../../kernel/menu/MenuContainer.h"

using namespace std;

class TcpMenuContainer : public MenuContainer
{
public:
	TcpMenuContainer();
	virtual ~TcpMenuContainer();

protected:
	virtual void fillOptions();
	virtual string getHeader();

};
#endif // TcpMenuContainer_h__
