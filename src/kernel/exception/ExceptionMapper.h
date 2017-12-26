#ifndef ExceptionMapper_h__
#define ExceptionMapper_h__

#include <iostream>
#include <string>

#include "runtime/RuntimeException.h"
#include "domain/DomainException.h"

using namespace std;


string handle(RuntimeException& e);
string handle(DomainException& e);


#endif // ExceptionMapper_h__
