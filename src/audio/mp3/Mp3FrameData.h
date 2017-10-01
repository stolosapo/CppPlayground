#ifndef Mp3FrameData_h__
#define Mp3FrameData_h__

#include <string>

using namespace std;

class Mp3FrameData
{
private:
	char _sign;
	unsigned int _length;
	unsigned int _position;
	string _description;

public:
	Mp3FrameData(
		const char sign, 
		const unsigned int length, 
		const unsigned int position, 
		const string description);

	virtual ~Mp3FrameData();

	const char sign() const;
	const unsigned int length() const;
	const unsigned int position() const;
	const string description() const;

};

#endif // Mp3FrameData_h__
