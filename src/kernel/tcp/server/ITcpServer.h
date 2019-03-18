#ifndef ITcpServer_h__
#define ITcpServer_h__

class ITcpServer
{
public:
	ITcpServer() { };
	virtual ~ITcpServer() { };

	virtual void start() = 0;
	virtual void action() = 0;
};

#endif // ITcpServer_h__
