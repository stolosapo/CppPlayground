#include "RuntimeException.h"

RuntimeException::RuntimeException(const string& cause) : runtime_error(cause), _cause(cause)
{

}

RuntimeException::~RuntimeException() throw()
{

}

const char* RuntimeException::cause() const throw()
{
	return _cause.c_str();
}
