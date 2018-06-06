#ifndef HttpProtocol_h__
#define HttpProtocol_h__

#include "../../tcp/protocol/ITcpProtocol.h"

class HttpProtocol : public ITcpProtocol
{
public:
	HttpProtocol(bool isServer);
	virtual ~HttpProtocol();

};

#endif // HttpProtocol_h__
