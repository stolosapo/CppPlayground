#ifndef TcpClientErrorCode_h__
#define TcpClientErrorCode_h__

#include "../../exception/domain/DomainErrorCode.h"

class TcpClientErrorCode
{
public:
	static const DomainErrorCode TCC0001;

	TcpClientErrorCode();
	virtual ~TcpClientErrorCode();

};

#endif // TcpClientErrorCode_h__