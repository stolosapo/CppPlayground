#include "GeneralDomainErrorCode.h"


const DomainErrorCode GeneralDomainErrorCode::GNR0001 = DomainErrorCode("GNR0001", "Cannot open file '%s'");
const DomainErrorCode GeneralDomainErrorCode::GNR0002 = DomainErrorCode("GNR0002", "Cannot find menu item with name '%s'");
const DomainErrorCode GeneralDomainErrorCode::GNR0003 = DomainErrorCode("GNR0003", "Menu item '%s' must not be MenuContainer");


GeneralDomainErrorCode::GeneralDomainErrorCode()
{

}

GeneralDomainErrorCode::~GeneralDomainErrorCode()
{

}
