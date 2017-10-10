#include "DomainException.h"

DomainException::DomainException(const string& code, const string& cause) : domain_error(code + ": " + cause), _code(code), _cause(cause)
{

}

DomainException::~DomainException() throw()
{

}

const char* DomainException::code() const throw()
{
	return _code.c_str();
}

const char* DomainException::cause() const throw()
{
	return _cause.c_str();
}
