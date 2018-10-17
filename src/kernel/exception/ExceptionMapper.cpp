#include "ExceptionMapper.h"

string handle(RuntimeException& e)
{
	return string(e.what());
}

string handle(DomainException& e)
{
	string message = e.message();

	string fullError = string(e.code()) + ": " + e.message();

	return fullError;
}
