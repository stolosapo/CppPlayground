#include "DomainErrorCode.h"

DomainErrorCode::DomainErrorCode(const char* code, const char* cause) : _code(code), _cause(cause)
{

}

DomainErrorCode::~DomainErrorCode()
{

}

const char* DomainErrorCode::code() const
{
	return _code;
}

const char* DomainErrorCode::cause() const
{
	return _cause;
}
