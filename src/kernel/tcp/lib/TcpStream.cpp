#include <arpa/inet.h>
#include <iostream>
#include "TcpStream.h"

using namespace std;

TcpStream::TcpStream(int sd, struct sockaddr_in* address) : m_sd(sd)
{
	char ip[50];
	inet_ntop(PF_INET, (struct in_addr*)&(address->sin_addr.s_addr),
			  ip, sizeof(ip)-1);
	m_peerIP = ip;
	m_peerPort = ntohs(address->sin_port);
}

TcpStream::TcpStream()
{

}

TcpStream::TcpStream(const TcpStream& stream)
{

}

TcpStream::~TcpStream()
{
	close(m_sd);
}



string TcpStream::getPeerIP()
{
	return this->m_peerIP;
}

int TcpStream::getPeerPort()
{
	return this->m_peerPort;
}

ssize_t TcpStream::send(const char* buffer, size_t len)
{
	return write(m_sd, buffer, len);
}

ssize_t TcpStream::send(string message)
{
	return send(message.c_str(), message.size());
}

ssize_t TcpStream::receive(char* buffer, size_t len)
{
	return read(m_sd, buffer, len);
}

ssize_t TcpStream::receive(string& message)
{
	char line[RECEIVE_SIZE];
	int len = receive(line, sizeof(line));

	if (len > 0)
	{
		line[len] = 0;
		message = (string) line;
	}
	else
	{
		message = "";
	}

	return len;
}

ssize_t TcpStream::receiveAll(string& message)
{
	string result = "";
	int cnt = 0;
	ssize_t currentSize = receive(result);
	ssize_t totalSize = currentSize;

	while (currentSize == RECEIVE_SIZE && cnt < 50)
	{
		cnt++;

		string s = "";
		currentSize = receive(s);

		result += s;
		totalSize += currentSize;
	}

	if (cnt >= 50)
	{
		result += "\n";
		result += "\n========================\n";
		result += "\n TOO LARGE RECEIVE TEXT \n";
		result += "\n MISSING TEXT...        \n";
		result += "\n========================\n";
		result += "\n";
	}

	message = result;

	return totalSize;
}