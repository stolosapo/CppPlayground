#ifndef TestState_h__
#define TestState_h__

#include <string>

#include "StatefullTcpServer.h"
#include "../ClientInfo.h"

using namespace std;

class TestState
{
private:
	string name;

public:
	TestState();
	virtual ~TestState();

	string getName();
	void setName(string name);

};

#endif // TestState_h__
