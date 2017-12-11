#ifndef TcpServerErrorCode_h__
#define TcpServerErrorCode_h__

#include "../../lib/exception/domain/DomainErrorCode.h"

class TcpServerErrorCode
{
public:
	static const DomainErrorCode TCS0001;
	static const DomainErrorCode TCS0002;

	TcpServerErrorCode();
	virtual ~TcpServerErrorCode();

};

#endif // TcpServerErrorCode_h__