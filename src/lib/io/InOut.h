
#ifndef InOut_h_
#define InOut_h_

#include <iostream>
#include <string>

using namespace std;

class InOut 
{
public:	
	InOut();
	virtual ~InOut();

	int inInt();
	string inString();
	string inLine();

	void outInt(int number);
	void outString(string message);
};

#endif /* InOut_h_ */