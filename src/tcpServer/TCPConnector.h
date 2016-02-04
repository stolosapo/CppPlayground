#ifndef TCPConnector_h__
#define TCPConnector_h__

#include <netinet/in.h>
#include "TCPStream.h"
 
class TCPConnector
{
  public:
    TCPStream* connect(int port, const char* server);
 
  private:
    int resolveHost(const char* host, struct in_addr* addr);
};

#endif // TCPConnector_h__