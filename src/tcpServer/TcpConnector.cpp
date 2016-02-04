#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "TcpConnector.h"
 
TcpStream* TcpConnector::connect(int port, const char* server)
{
    struct sockaddr_in address;
 
    memset (&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    if (resolveHost(server, &(address.sin_addr)) != 0) {
        inet_pton(PF_INET, server, &(address.sin_addr));        
    } 
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    if (::connect(sd, (struct sockaddr*)&address, sizeof(address)) != 0) {
        return NULL;
    }
    return new TcpStream(sd, &address);
}

int TcpConnector::resolveHost(const char* host, struct in_addr* addr)
{
    struct addrinfo *res;
 
    int result = getaddrinfo (host, NULL, NULL, &res);
    if (result == 0) {
        memcpy(addr, &((struct sockaddr_in *) res->ai_addr)->sin_addr, 
               sizeof(struct in_addr));
        freeaddrinfo(res);
    }
    return result;
}