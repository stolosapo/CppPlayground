#include <arpa/inet.h>
#include "TcpStream.h"

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
    
ssize_t TcpStream::receive(char* buffer, size_t len)
{
	return read(m_sd, buffer, len);
}
