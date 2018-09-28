#ifndef Argument_h__
#define Argument_h__

#include <string>

using namespace std;

class Argument
{
private:
    string argc;
    string argv;

public:
	Argument(const string& argc, const string& argv);
    Argument(const Argument& arg);
	virtual ~Argument();

	string getArgc() const;
    string getArgv() const;
};

#endif // Argument_h__
