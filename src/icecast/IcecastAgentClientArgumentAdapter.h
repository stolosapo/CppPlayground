#ifndef IcecastAgentClientArgumentAdapter_h__
#define IcecastAgentClientArgumentAdapter_h__

#include <string>

#include "../kernel/arguments/ArgumentAdapter.h"

using namespace std;

class IcecastAgentClientArgumentAdapter: public ArgumentAdapter
{
private:
    static const string CONFIG_FILE;

public:
	IcecastAgentClientArgumentAdapter(ArgumentService* argService);
	virtual ~IcecastAgentClientArgumentAdapter();

    virtual void registerArguments();

protected:
    virtual string title();

    bool hasAgentClientConfigFilename() const;
    string getAgentClientConfigFilename() const;

};

#endif // IcecastAgentClientArgumentAdapter_h__
