#ifndef ClientInfo_h__
#define ClientInfo_h__

#include <string>
#include "TcpStream.h"

using namespace std;

class ClientInfo
{
private:
	string name;
	string ip;
	string hostname;

	TcpStream *stream;
	
public:
	ClientInfo(TcpStream *stream);
	virtual ~ClientInfo();

	string getName();
	string getIp();
	string getHostname();

	TcpStream* getStream();

	void setName(string name);
	void setIp(string ip);
	void setHostname(string hostname);

};

#endif // ClientInfo_h__