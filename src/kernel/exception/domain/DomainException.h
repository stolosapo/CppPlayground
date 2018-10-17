#ifndef DomainException_h__
#define DomainException_h__

#include <iostream>
#include <string>
#include "../runtime/RuntimeException.h"
#include "DomainErrorCode.h"

using namespace std;

class DomainException: public RuntimeException
{
private:
	const DomainErrorCode& _errorCode;
	string _arg;

public:
	DomainException(const DomainErrorCode& errorCode);
	DomainException(const DomainErrorCode& errorCode, string arg);
	virtual ~DomainException() throw();

	virtual const char* fullError() const throw();
	virtual string message() const throw();
	virtual const char* code() const throw();

};

#endif // DomainException_h__
