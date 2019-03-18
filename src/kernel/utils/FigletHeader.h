#ifndef FigletHeader_h__
#define FigletHeader_h__

#include <iostream>
#include <string>
#include <vector>


using namespace std;

class FigletHeader
{
private:
	int getRandomNumber();

protected:
	vector<string> headers;

	virtual void fillHeaders() = 0;

public:
	FigletHeader();
	virtual ~FigletHeader();

	virtual string getRandomHeader();
	virtual string getHeader(int index);
	
};

#endif // FigletHeader_h__