#ifndef Excecutor_h__
#define Excecutor_h__

class Excecutor
{
public:
	Excecutor();
	virtual ~Excecutor();

	int forkAndExit();
	int forkAndWait();
	int forkAndExcecute(char* args[]);

private:
	int createChildProcess();

};

#endif // Excecutor_h__