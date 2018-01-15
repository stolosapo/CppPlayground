#ifndef Score4MenuContainer_h__
#define Score4MenuContainer_h__

#include <string>

#include "../../../kernel/menu/MenuContainer.h"

using namespace std;

class Score4MenuContainer : public MenuContainer
{
public:
	Score4MenuContainer();
	virtual ~Score4MenuContainer();

protected:
	virtual void fillOptions();
	virtual string getHeader();

};
#endif // Score4MenuContainer_h__
