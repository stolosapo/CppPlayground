#ifndef DataModelErrorCode_h__
#define DataModelErrorCode_h__

#include "../../exception/domain/DomainErrorCode.h"

class DataModelErrorCode
{
public:
    static const DomainErrorCode DTM0001;
    static const DomainErrorCode DTM0002;
    static const DomainErrorCode DTM0003;

    DataModelErrorCode();
    virtual ~DataModelErrorCode();

};

#endif // DataModelErrorCode_h__
