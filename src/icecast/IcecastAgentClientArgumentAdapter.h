#ifndef IcecastAgentClientArgumentAdapter_h__
#define IcecastAgentClientArgumentAdapter_h__

#include <string>

#include "../kernel/arguments/ArgumentAdapter.h"

using namespace std;

class IcecastAgentClientArgumentAdapter: public ArgumentAdapter
{
public:
	IcecastAgentClientArgumentAdapter(ArgumentService* argService);
	virtual ~IcecastAgentClientArgumentAdapter();

    virtual string help();
    virtual void registerArguments() const;

protected:
    bool hasAgentClientConfigFilename() const;
    string getAgentClientConfigFilename() const;

};

#endif // IcecastAgentClientArgumentAdapter_h__
