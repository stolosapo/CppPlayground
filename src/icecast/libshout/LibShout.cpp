#include "LibShout.h"

LibShout::LibShout(ILogService *logSrv, IcecastClientConfig* config)
{
	this->logSrv = logSrv;
	this->config = config;
}

LibShout::~LibShout()
{

}

void LibShout::initializeShout()
{
	shoutInit();

	shoutNew();

	if (setHost(config->getHostname()) != 0)
	{
		return;
	}
}


/*
	// LibShout

	shout_t *shout;
	unsigned char buff[4096];
	long read, ret, total;

	shout_init();

	if (!(shout = shout_new())) {
		printf("Could not allocate shout_t\n");
		return;
	}

	if (shout_set_host(shout, "giss.tv") != SHOUTERR_SUCCESS) {
		printf("Error setting hostname: %s\n", shout_get_error(shout));
		return;
	}


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