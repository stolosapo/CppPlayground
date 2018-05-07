#ifndef PlaylistErrorCode_h__
#define PlaylistErrorCode_h__

#include "../../../exception/domain/DomainErrorCode.h"

class PlaylistErrorCode
{
public:
	static const DomainErrorCode PLS0001;
	static const DomainErrorCode PLS0002;
	static const DomainErrorCode PLS0003;
	static const DomainErrorCode PLS0004;
	static const DomainErrorCode PLS0005;

	PlaylistErrorCode();
	virtual ~PlaylistErrorCode();

};

#endif // PlaylistErrorCode_h__
