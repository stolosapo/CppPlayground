#include <stdio.h>
#include "DomainException.h"

DomainException::DomainException(const DomainErrorCode& errorCode) : RuntimeException(errorCode.cause()), _errorCode(errorCode), _arg("")
{

}

DomainException::DomainException(const DomainErrorCode& errorCode, string arg) : RuntimeException(errorCode.cause()), _errorCode(errorCode), _arg(arg)
{

}

DomainException::~DomainException() throw()
{

}

const char* DomainException::fullError() const throw()
{
	return cause();
}

string DomainException::message() const throw()
{
	char* mess = new char[1024];

	sprintf(mess, cause(), _arg.c_str());

	string res = string(mess);

    delete[] mess;

	return res;
}

const char* DomainException::code() const throw()
{
	return _errorCode.code();
}
