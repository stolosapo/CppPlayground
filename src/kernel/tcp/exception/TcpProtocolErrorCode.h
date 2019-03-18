#ifndef TcpProtocolErrorCode_h__
#define TcpProtocolErrorCode_h__

#include "../../exception/domain/DomainErrorCode.h"

class TcpProtocolErrorCode
{
public:
        static const DomainErrorCode TCP0001;

	TcpProtocolErrorCode();
	virtual ~TcpProtocolErrorCode();

};

#endif // TcpProtocolErrorCode_h__
