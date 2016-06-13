#include <iostream>
#include <vector>

using namespace std;

#ifndef PRIMEFACTOR_H_
#define PRIMEFACTOR_H_

class PrimeFactor 
{
public:	
	static vector<int> upTo(int upperBound);
	static int getByIndex(int index);
	static int getNextPrime(int prime);
	static bool isPrime(int number);
};

#endif /* PRIMEFACTOR_H_ */
