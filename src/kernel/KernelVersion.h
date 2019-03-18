#ifndef KernelVersion_h__
#define KernelVersion_h__

#include <iostream>

#include "version/Version.h"

using namespace std;

class KernelVersion : public Version
{
public:
	KernelVersion();
	virtual ~KernelVersion();

};

#endif // KernelVersion_h__
