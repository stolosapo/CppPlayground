#ifndef TcpStream_h__
#define TcpStream_h__

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
 
using namespace std;
 
class TcpStream
{
    int     m_sd;
    string  m_peerIP;
    int     m_peerPort;
 
  public:
    friend class TcpAcceptor;
    friend class TcpConnector;
 
    ~TcpStream();
 
    ssize_t send(const char* buffer, size_t len);
    ssize_t receive(char* buffer, size_t len);
 
    string getPeerIP();
    int getPeerPort();
 
  private:
    TcpStream(int sd, struct sockaddr_in* address);
    TcpStream();
    TcpStream(const TcpStream& stream);
};

#endif // TcpStream_h__