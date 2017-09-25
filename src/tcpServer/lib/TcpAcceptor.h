#ifndef TcpAcceptor_h__
#define TcpAcceptor_h__

#include <string>
#include <netinet/in.h>
#include "TcpStream.h"
 
using namespace std;
 
class TcpAcceptor
{
    int    m_lsd;
    string m_address;
    int    m_port;
    bool   m_listening;
 
public:
    TcpAcceptor(int port, const char* address = "");
    ~TcpAcceptor();

    int start();
    TcpStream* accept();
 
private:
    TcpAcceptor() {}
};

#endif // TcpAcceptor_h__