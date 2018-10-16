#ifndef IcecastAgentArgumentAdapter_h__
#define IcecastAgentArgumentAdapter_h__

#include <string>

#include "../kernel/arguments/ArgumentAdapter.h"

using namespace std;

class IcecastAgentArgumentAdapter: public ArgumentAdapter
{
public:
	IcecastAgentArgumentAdapter(ArgumentService* argService);
	virtual ~IcecastAgentArgumentAdapter();

protected:
    bool hasAgentConfigFilename() const;
    string getAgentConfigFilename() const;

};

#endif // IcecastAgentArgumentAdapter_h__
