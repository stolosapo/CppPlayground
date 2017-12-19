#include "ExceptionMapper.h"

string handle(RuntimeException& e)
{
	return string(e.what());
}

string handle(DomainException& e)
{
	return string(e.code()) + ": " + string(e.what());
}