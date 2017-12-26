#include "DomainException.h"

DomainException::DomainException(const DomainErrorCode& errorCode) : RuntimeException(errorCode.cause()), _errorCode(errorCode)
{

}

DomainException::~DomainException() throw()
{

}

const char* DomainException::what() const throw()
{
	return cause();
}

const char* DomainException::code() const throw()
{
	return _errorCode.code();
}
