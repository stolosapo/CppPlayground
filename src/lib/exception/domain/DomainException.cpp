#include "DomainException.h"

DomainException::DomainException(const DomainErrorCode& errorCode) : RuntimeException(errorCode.cause()), _errorCode(errorCode)
{

}

DomainException::~DomainException() throw()
{

}

const char* DomainException::fullError() const throw()
{
	string mess = string(_errorCode.code()) + ": " + cause();
	return mess.c_str();
}

const char* DomainException::code() const throw()
{
	return _errorCode.code();
}
