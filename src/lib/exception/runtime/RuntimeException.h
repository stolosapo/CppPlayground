#ifndef RuntimeException_h__
#define RuntimeException_h__

#include <iostream>
#include <exception>

using namespace std;

class RuntimeException: public exception
{
private:
	string _cause;

public:
	RuntimeException(const string& cause);
	virtual ~RuntimeException() throw();

	virtual const char* what() const throw();
	virtual const char* cause() const throw();

};

#endif // RuntimeException_h__
