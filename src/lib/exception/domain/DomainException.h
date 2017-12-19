#ifndef DomainException_h__
#define DomainException_h__

#include <iostream>
#include "../runtime/RuntimeException.h"
#include "DomainErrorCode.h"

using namespace std;

class DomainException: public RuntimeException
{
private:
	const DomainErrorCode& _errorCode;

public:
	DomainException(const DomainErrorCode& errorCode);
	virtual ~DomainException() throw();

	virtual const char* what() const throw();
	virtual const char* code() const throw();

};

#endif // DomainException_h__
