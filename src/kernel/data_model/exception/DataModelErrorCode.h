#ifndef DataModelErrorCode_h__
#define DataModelErrorCode_h__

#include "../../exception/domain/DomainErrorCode.h"

class DataModelErrorCode
{
public:
    static const DomainErrorCode DTM0001;

    DataModelErrorCode();
    virtual ~DataModelErrorCode();

};

#endif // DataModelErrorCode_h__
