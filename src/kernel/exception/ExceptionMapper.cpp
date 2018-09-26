#include "ExceptionMapper.h"

string handle(RuntimeException& e)
{
	return string(e.what());
}

string handle(DomainException& e)
{
	const char* message = e.message();

	string fullError = string(e.code()) + ": " + string(message);

    // delete message;

	return fullError;
}
