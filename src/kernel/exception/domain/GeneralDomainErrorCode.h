#ifndef GeneralDomainErrorCode_h__
#define GeneralDomainErrorCode_h__

#include "DomainErrorCode.h"

class GeneralDomainErrorCode
{
public:
	static const DomainErrorCode GNR0001;
	static const DomainErrorCode GNR0002;
	static const DomainErrorCode GNR0003;

	GeneralDomainErrorCode();
	virtual ~GeneralDomainErrorCode();

};

#endif // GeneralDomainErrorCode_h__
