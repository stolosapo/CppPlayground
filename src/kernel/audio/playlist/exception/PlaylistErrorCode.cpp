#include "PlaylistErrorCode.h"


const DomainErrorCode PlaylistErrorCode::PLS0001 = DomainErrorCode("PLS0001", "Invalid playlist track number '%s'");
const DomainErrorCode PlaylistErrorCode::PLS0002 = DomainErrorCode("PLS0002", "Invalid history track number '%s'");
const DomainErrorCode PlaylistErrorCode::PLS0003 = DomainErrorCode("PLS0003", "Cannot find playlist index of track '%s'");
const DomainErrorCode PlaylistErrorCode::PLS0004 = DomainErrorCode("PLS0004", "Cannot find metadata track '%s'");
const DomainErrorCode PlaylistErrorCode::PLS0005 = DomainErrorCode("PLS0005", "Cannot load metadata for track '%s'");


PlaylistErrorCode::PlaylistErrorCode()
{

}

PlaylistErrorCode::~PlaylistErrorCode()
{

}
