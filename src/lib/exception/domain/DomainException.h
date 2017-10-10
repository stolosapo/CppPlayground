#ifndef DomainException_h__
#define DomainException_h__

#include <iostream>
#include <exception>

using namespace std;

class DomainException: public domain_error
{
private:
	string _code;
	string _cause;

public:
	explicit DomainException(const string& code, const string& cause);
	virtual ~DomainException() throw();

	virtual const char* code() const throw();
	virtual const char* cause() const throw();

};

#endif // DomainException_h__
