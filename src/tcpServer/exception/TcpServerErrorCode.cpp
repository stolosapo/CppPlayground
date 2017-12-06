#include "TcpServerErrorCode.h"



const DomainErrorCode TcpServerErrorCode::TCS0001 = DomainErrorCode("TCS0001", "Could not start the Server");
const DomainErrorCode TcpServerErrorCode::TCS0002 = DomainErrorCode("TCS0002", "Server denied access to the client: %s");



TcpServerErrorCode::TcpServerErrorCode()
{

}

TcpServerErrorCode::~TcpServerErrorCode()
{

}