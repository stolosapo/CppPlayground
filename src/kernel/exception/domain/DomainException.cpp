#include <stdio.h>
#include "DomainException.h"

DomainException::DomainException(const DomainErrorCode& errorCode) : RuntimeException(errorCode.cause()), _errorCode(errorCode), _arg("")
{

}

DomainException::DomainException(const DomainErrorCode& errorCode, const char* arg) : RuntimeException(errorCode.cause()), _errorCode(errorCode), _arg(arg)
{

}

DomainException::~DomainException() throw()
{

}

const char* DomainException::fullError() const throw()
{
	return cause();
}

const char* DomainException::message() const throw()
{
	char* mess = new char[1024];

	sprintf(mess, cause(), _arg);

	return string(mess).c_str();
}

const char* DomainException::code() const throw()
{
	return _errorCode.code();
}
