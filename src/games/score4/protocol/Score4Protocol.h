#ifndef Score4Protocol_h__
#define Score4Protocol_h__

#include "../../../kernel/tcp/protocol/ITcpProtocol.h"

class Score4Protocol: public ITcpProtocol
{
public:
	Score4Protocol(bool isServer);
	virtual ~Score4Protocol();

};

#endif // Score4Protocol_h__
