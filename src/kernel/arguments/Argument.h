#ifndef Argument_h__
#define Argument_h__

class Argument
{
private:
        const char* argc;
        const char* argv;

public:
	Argument(const char* argc, const char* argv);
	virtual ~Argument();

	const char* getArgc() const;
        const char* getArgv() const;
};

#endif // Argument_h__
