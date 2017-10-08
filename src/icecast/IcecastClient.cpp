#include "IcecastClient.h"

#include "config/IcecastClientConfigLoader.h"
#include "../audio/mp3/Mp3Parser.h"


#include "../lib/converter/Convert.h"

#ifdef ICECAST
#include <shout/shout.h>
#endif


IcecastClient::IcecastClient(ILogService *logSrv) : ITcpClient()
{
	this->logSrv = logSrv;
}

IcecastClient::~IcecastClient()
{
	if (protocol != NULL)
	{
		// delete protocol;
	}

	if (config != NULL)
	{
		// delete config;
	}
}

void IcecastClient::loadConfig()
{
	IcecastClientConfigLoader* loader = new IcecastClientConfigLoader("icecast.config");

	this->config = loader->load();

	this->protocol = new IcecastProtocol(this->config);

	delete loader;
}

void IcecastClient::initializeShout()
{
#ifdef ICECAST
	shout_init();

	/* Allocation */
	if (!(shout = shout_new())) 
	{
		logSrv->error("Could not allocate shout_t");
		return;
	}

	/* Host */
	if (shout_set_host(shout, config->getHostname().c_str()) != SHOUTERR_SUCCESS) 
	{
		// printf("Error setting hostname: %s\n", shout_get_error(shout));
		logSrv->error("Error setting hostname: " + string(shout_get_error(shout)));
		return;
	}
#else
	logSrv->printl("Icecast feature is not enabled, try to pass the WITH_ICECAST=1 param when Make.");
#endif
}

void IcecastClient::streamAudio()
{
	// Mp3Parser mp3Parser;

	// mp3Parser.parse();

	initializeShout();


	/* LibShout */

	// shout_t *shout;
	unsigned char buff[4096];
	long read, ret, total;

	// shout_init();

	// if (!(shout = shout_new())) {
	// 	printf("Could not allocate shout_t\n");
	// 	return;
	// }

	// if (shout_set_host(shout, "giss.tv") != SHOUTERR_SUCCESS) {
	// 	printf("Error setting hostname: %s\n", shout_get_error(shout));
	// 	return;
	// }

	/*
	if (shout_set_protocol(shout, SHOUT_PROTOCOL_HTTP) != SHOUTERR_SUCCESS) {
		printf("Error setting protocol: %s\n", shout_get_error(shout));
		return;
	}

	if (shout_set_port(shout, 8001) != SHOUTERR_SUCCESS) {
		printf("Error setting port: %s\n", shout_get_error(shout));
		return;
	}

	if (shout_set_password(shout, "j0vys") != SHOUTERR_SUCCESS) {
		printf("Error setting password: %s\n", shout_get_error(shout));
		return;
	}
	if (shout_set_mount(shout, "/thefirstkube.mp3") != SHOUTERR_SUCCESS) {
		printf("Error setting mount: %s\n", shout_get_error(shout));
		return;
	}

	if (shout_set_user(shout, "source") != SHOUTERR_SUCCESS) {
		printf("Error setting user: %s\n", shout_get_error(shout));
		return;
	}

	if (shout_set_format(shout, SHOUT_FORMAT_MP3) != SHOUTERR_SUCCESS) {
		printf("Error setting format: %s\n", shout_get_error(shout));
		return;
	}

	if (shout_set_nonblocking(shout, 1) != SHOUTERR_SUCCESS) {
	  printf("Error setting non-blocking mode: %s\n", shout_get_error(shout));
	  return;
	}
	
	ret = shout_open(shout);
	if (ret == SHOUTERR_SUCCESS)
	  ret = SHOUTERR_CONNECTED;

	if (ret == SHOUTERR_BUSY)
	  printf("Connection pending...\n");

	while (ret == SHOUTERR_BUSY) {
	  usleep(10000);
	  ret = shout_get_connected(shout);
	}
	
		if (ret == SHOUTERR_CONNECTED) {
		printf("Connected to server...\n");
		total = 0;
		while (1) {
			read = fread(buff, 1, sizeof(buff), stdin);
			total = total + read;

			cout << "Read: "<< total << endl;

			if (read > 0) {
				ret = shout_send(shout, buff, read);
				cout << "Send: "<< read << endl;
				if (ret != SHOUTERR_SUCCESS) {
					printf("DEBUG: Send error: %s\n", shout_get_error(shout));
					break;
				}
			} else {
				break;
			}
			if (shout_queuelen(shout) > 0)
				printf("DEBUG: queue length: %d\n", 
                                        (int)shout_queuelen(shout));

			shout_sync(shout);
		}
	} else {
		printf("Error connecting: %s\n", shout_get_error(shout));
	}

	shout_close(shout);

	shout_shutdown();

	*/
}

void IcecastClient::action()
{
	streamAudio();

	return;

	loadConfig();

	const int BUFF_SIZE = 2048;
	string inMessage;

	string hostname = config->getHostname();
	string port = config->getPort();
	int intPort = Convert<int>::StringToNumber(port);

	logSrv->info("Client is connecting to server-> " + hostname + ":" + port);
	stream = connector->connect(intPort, hostname.c_str());

 	if (stream)
	{
		string outMessage = protocol->connectionRequest();

		stream->send(outMessage);

		logSrv->info("Sent:\n" + outMessage);

		char* inBuffer = new char[BUFF_SIZE];
		// stream->receive(inMessage);
		stream->receive(inBuffer, BUFF_SIZE);
		inMessage.assign(inBuffer, BUFF_SIZE);

		logSrv->info("Received:\n" + inMessage);

		/* Start streaming the audio */
		streamAudio();


		delete stream;
    }
    else
    {
    	logSrv->error("Fail to connect");
    }
}
