#ifndef ClientInfo_h__
#define ClientInfo_h__

#include <string>
#include "TcpStream.h"

using namespace std;

class ClientInfo
{
private:
	int index;
	string name;
	string ip;
	string hostname;

	TcpStream *stream;
	void* server;
	
public:
	ClientInfo(void *server, TcpStream *stream, int index);
	virtual ~ClientInfo();

	int getIndex();
	string getName();
	string getIp();
	string getHostname();

	TcpStream* getStream();
	void* getServer();

	void setName(string name);
	void setIp(string ip);
	void setHostname(string hostname);

};

#endif // ClientInfo_h__