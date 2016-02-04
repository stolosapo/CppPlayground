#ifndef TcpConnector_h__
#define TcpConnector_h__

#include <netinet/in.h>
#include "TcpStream.h"
 
class TcpConnector
{
  public:
    TcpStream* connect(int port, const char* server);
 
  private:
    int resolveHost(const char* host, struct in_addr* addr);
};

#endif // TcpConnector_h__