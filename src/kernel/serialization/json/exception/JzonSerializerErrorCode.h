#ifndef JzonSerializerErrorCode_h__
#define JzonSerializerErrorCode_h__

#include "../../../exception/domain/DomainErrorCode.h"

class JzonSerializerErrorCode
{
public:
    static const DomainErrorCode JSR0001;

    JzonSerializerErrorCode();
    virtual ~JzonSerializerErrorCode();

};

#endif // JzonSerializerErrorCode_h__
