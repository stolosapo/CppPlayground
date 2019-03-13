#ifndef ClientInfo_h__
#define ClientInfo_h__

#include <string>
#include "lib/TcpStream.h"
#include "../task/Thread.h"

using namespace std;

class ClientInfo
{
private:
	int index;

	Thread* thread;

	string name;
	string ip;
	string hostname;

	TcpStream *stream;
	void* server;

public:
	ClientInfo(void *server, TcpStream *stream, Thread *thread, int index);
	ClientInfo(void *server, TcpStream *stream, int index);
	virtual ~ClientInfo();

	int getIndex();

	Thread* getThread();

	string getName();
	string getIp();
	string getHostname();
	string getIdentity();

	TcpStream* getStream();
	void* getServer();

	void setName(string name);
	void setIp(string ip);
	void setHostname(string hostname);

};

#endif // ClientInfo_h__
