#include "Excecutor.h"

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;


Excecutor::Excecutor()
{

}

Excecutor::~Excecutor()
{

}

int Excecutor::createChildProcess()
{
	pid_t PID = 0;
	int result = 0, filedes[2], status;

	/* Create child process */
	PID = fork();

	if (PID == -1)
	{
		return -1;
	}

	result = pipe(filedes);

	if (PID != 0)
	{
		cout << "Created child precess. PID: " << PID << endl;
	}

	if (result == -1)
	{
		return -1;
	}

	return PID;
}

int Excecutor::forkAndExit()
{
	pid_t PID = 0;
	int status;

	/* Create child process */
	PID = createChildProcess();

	if (PID == -1)
	{
		return 1;
	}

	/* This is the child process */
	if (PID == 0)
	{
		/* Disassociate process group and controlling terminal */
		setsid();
	}

	/* This is the parent process */
	else
	{
		/* Terminate Application */
		exit(0);
	}

	return 0;
}

int Excecutor::forkAndWait()
{
	pid_t PID = 0;
	int status;

	/* Create child process */
	PID = createChildProcess();

	if (PID == -1)
	{
		return 1;
	}

	/* This is the child process */
	if (PID == 0)
	{
		// /* Disassociate process group and controlling terminal */
		// setsid();
	}

	/* This is the parent process */
	else
	{
		// Wait for thw child process to return
		waitpid(PID, &status, 0);

		cout << "Process returned " << WEXITSTATUS(status) << endl;
		cout << "Press enter." << endl;
	}

	return 0;
}

int Excecutor::forkAndExcecute(char* args[])
{
	pid_t PID = 0;
	int status;

	/* Create child process */
	PID = createChildProcess();

	if (PID == -1)
	{
		return 1;
	}

	/* This is the child process */
	if (PID == 0)
	{
		string prog = "./runner";

		// Execute the program
		execvp(prog.c_str(), args);
	}

	/* This is the parent process */
	else
	{
		// Wait for thw child process to return
		waitpid(PID, &status, 0);

		cout << "Process returned " << WEXITSTATUS(status) << endl;
		cout << "Press enter." << endl;
	}

	return 0;
}