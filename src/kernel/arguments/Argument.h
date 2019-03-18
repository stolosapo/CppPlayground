#ifndef Argument_h__
#define Argument_h__

#include <string>

using namespace std;

class Argument
{
private:
    string name;
    string value;

public:
	Argument(const string& name, const string& value);
    Argument(const Argument& arg);
	virtual ~Argument();

	string getName() const;
    string getValue() const;
};

#endif // Argument_h__
