#ifndef TcpProtocol_h__
#define TcpProtocol_h__

#include <string>

using namespace std;

class TcpProtocol
{
private:
	static const char* const ACK_COMMANDS[];
	static const char* const COMMANDS[];

	static void toLower(string command);
	static bool exists(const char* const array[], int size, string command);

public:
	static const char* PROMPT;

	static const char* CLIENT_CONNECT;
	static const char* OK;
	static const char* DENIED;
	static const char* INVALID_COMMAND;

	static const char* HELP;
	static const char* EXIT;
	static const char* SHUTDOWN;

	static bool exit(string command);
	static bool error(string command);
	static bool shutdown(string command);
	static bool validCommand(string command);
	static bool validAckCommand(string command);

	TcpProtocol();
	virtual ~TcpProtocol();

};

#endif // TcpProtocol_h__