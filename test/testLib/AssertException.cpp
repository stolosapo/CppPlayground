#include "AssertException.h"

AssertException::AssertException(const char* cause) : _cause(cause)
{

}

AssertException::AssertException(const string& cause) : _cause(cause)
{

}

AssertException::~AssertException() throw()
{

}

const char* AssertException::what() const throw()
{
	return _cause.c_str();
}