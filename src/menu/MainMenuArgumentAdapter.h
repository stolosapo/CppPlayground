#ifndef MainMenuArgumentAdapter_h__
#define MainMenuArgumentAdapter_h__

#include <string>

#include "../kernel/arguments/ArgumentAdapter.h"

using namespace std;

class MainMenuArgumentAdapter: public ArgumentAdapter
{
public:
	MainMenuArgumentAdapter(ArgumentService* argService);
	virtual ~MainMenuArgumentAdapter();

protected:
    bool hasMenuItem() const;
    string getMenuItem() const;

};

#endif // MainMenuArgumentAdapter_h__
