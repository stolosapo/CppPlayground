#include "EncodingDomainErrorCode.h"


const DomainErrorCode EncodingDomainErrorCode::ENC0001 = DomainErrorCode("ENC0001", "Lame feature is not enabled, try to pass the WITH_LAME=1 param when Make");
const DomainErrorCode EncodingDomainErrorCode::ENC0002 = DomainErrorCode("ENC0002", "Lame parameters failed to initialize properly");


EncodingDomainErrorCode::EncodingDomainErrorCode()
{

}

EncodingDomainErrorCode::~EncodingDomainErrorCode()
{

}
