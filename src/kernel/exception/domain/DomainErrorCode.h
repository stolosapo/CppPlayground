#ifndef DomainErrorCode_h__
#define DomainErrorCode_h__

#include <iostream>
#include "../runtime/RuntimeException.h"

using namespace std;

class DomainErrorCode
{
private:
	const char* _code;
	const char* _cause;

public:
	DomainErrorCode(const char* code, const char* cause);
	virtual ~DomainErrorCode();

	virtual const char* code() const;
	virtual const char* cause() const;

};

#endif // DomainErrorCode_h__
