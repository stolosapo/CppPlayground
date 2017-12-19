#ifndef RuntimeException_h__
#define RuntimeException_h__

#include <iostream>
#include <exception>

using namespace std;

class RuntimeException: public exception
{
private:
	const char* _cause;

public:
	RuntimeException(const char* cause);
	virtual ~RuntimeException() throw();

	virtual const char* what() const throw();
	virtual const char* cause() const throw();
};

#endif // RuntimeException_h__
