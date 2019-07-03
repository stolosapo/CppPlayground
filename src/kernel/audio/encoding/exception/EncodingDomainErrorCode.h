#ifndef EncodingDomainErrorCode_h__
#define EncodingDomainErrorCode_h__

#include "../../../exception/domain/DomainErrorCode.h"

class EncodingDomainErrorCode
{
public:
    static const DomainErrorCode ENC0001;
    static const DomainErrorCode ENC0002;
    static const DomainErrorCode ENC0003;

	EncodingDomainErrorCode();
	virtual ~EncodingDomainErrorCode();

};

#endif // EncodingDomainErrorCode_h__
