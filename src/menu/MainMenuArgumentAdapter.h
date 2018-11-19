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

    virtual string help();
    virtual void registerArguments();

protected:
    bool hasTreeArg() const;

    bool hasMenuItem() const;
    string getMenuItem() const;

};

#endif // MainMenuArgumentAdapter_h__
