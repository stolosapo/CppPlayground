#include "RuntimeException.h"

RuntimeException::RuntimeException(const string& cause) : _cause(cause)
{

}

RuntimeException::~RuntimeException() throw()
{

}

const char* AssertException::what() const throw()
{
	return _cause.c_str();
}

const char* RuntimeException::cause() const throw()
{
	return _cause.c_str();
}
