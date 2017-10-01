#ifndef Mp3FrameData_h__
#define Mp3FrameData_h__

#include <string>

using namespace std;

class Mp3FrameData
{
private:
	char sign;
	unsigned int length;
	unsigned int position;
	string description;

public:
	Mp3FrameData(
		const char sign, 
		const unsigned int length, 
		const unsigned int position, 
		const string description);

	virtual ~Mp3FrameData();

	const char getSign() const;
	const unsigned int getLength() const;
	const unsigned int getPosition() const;
	const string getDescription() const;

};

#endif // Mp3FrameData_h__
