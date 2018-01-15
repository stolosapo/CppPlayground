#ifndef GameMenuContainer_h__
#define GameMenuContainer_h__

#include <string>

#include "../kernel/menu/MenuContainer.h"

using namespace std;

class GameMenuContainer : public MenuContainer
{
public:
	GameMenuContainer();
	virtual ~GameMenuContainer();

protected:
	virtual void fillOptions();
	virtual string getHeader();

};
#endif // GameMenuContainer_h__
