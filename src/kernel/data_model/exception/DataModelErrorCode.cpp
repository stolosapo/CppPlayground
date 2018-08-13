#include "DataModelErrorCode.h"


const DomainErrorCode DataModelErrorCode::DTM0001 = DomainErrorCode("DTM0001", "Invalid property type");
const DomainErrorCode DataModelErrorCode::DTM0002 = DomainErrorCode("DTM0002", "Cannot create OBJECT property without factory method");
const DomainErrorCode DataModelErrorCode::DTM0003 = DomainErrorCode("DTM0003", "Cannot invoke property's model factory, factory is NULL");


DataModelErrorCode::DataModelErrorCode()
{

}

DataModelErrorCode::~DataModelErrorCode()
{

}
