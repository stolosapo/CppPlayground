#ifndef ClientInfo_h__
#define ClientInfo_h__

#include <string>
#include "lib/TcpStream.h"
#include "../lib/task/Thread.h"

using namespace std;

class ClientInfo
{
private:
	int index;

	long threadNumber;
	Thread* thread;

	string name;
	string ip;
	string hostname;

	TcpStream *stream;
	void* server;

public:
	ClientInfo(void *server, TcpStream *stream, Thread *thread, int index);
	virtual ~ClientInfo();

	int getIndex();

	long getThreadNumber();
	Thread* getThread();

	string getName();
	string getIp();
	string getHostname();

	TcpStream* getStream();
	void* getServer();

	void setThreadNumber(long threadNumber);

	void setName(string name);
	void setIp(string ip);
	void setHostname(string hostname);

};

#endif // ClientInfo_h__
