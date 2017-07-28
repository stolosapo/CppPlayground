#ifndef AssertException_h__
#define AssertException_h__

#include <iostream>
#include <exception>

#include "UnitTestFunction.h"

using namespace std;

class AssertException: public exception
{
private:
	string _cause;

public:
	AssertException(const char* cause);
	AssertException(const string& cause);
	virtual ~AssertException() throw();

	virtual const char* what() const throw();
	
};

#endif // AssertException_h__
