#include "EncodingDomainErrorCode.h"


const DomainErrorCode EncodingDomainErrorCode::ENC0001 = DomainErrorCode("ENC0001", "Lame feature is not enabled, try to pass the WITH_LAME=1 param when Make");
const DomainErrorCode EncodingDomainErrorCode::ENC0002 = DomainErrorCode("ENC0002", "Lame parameters failed to initialize properly");
const DomainErrorCode EncodingDomainErrorCode::ENC0003 = DomainErrorCode("ENC0003", "Lame failed to encode the pcm file correctly: '%s'");


EncodingDomainErrorCode::EncodingDomainErrorCode()
{

}

EncodingDomainErrorCode::~EncodingDomainErrorCode()
{

}
