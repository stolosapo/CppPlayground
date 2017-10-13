#ifndef LibShout_h__
#define LibShout_h__

#include <string>
#include "../config/IcecastClientConfig.h"
#include "../../log/ILogService.h"

#ifdef ICECAST
#include <shout/shout.h>
#endif

using namespace std;

class LibShout
{
private:
	ILogService *logSrv;

	IcecastClientConfig* config;

#ifdef ICECAST
	shout_t* shout;
#endif

	/* initializes the shout library. Must be called before anything else */
	void shoutInit();

	/* shuts down the shout library, deallocating any global storage. Don't call
	 * anything afterwards */
	void shoutShutdown();

	/* returns a static version string.  Non-null parameters will be set to the
	 * value of the library major, minor, and patch levels, respectively */
	string shoutVersion(int *major, int *minor, int *patch);

	/* Allocates and sets up a new shout_t.  Returns NULL if it can't get enough
	 * memory.  The returns shout_t must be disposed of with shout_free. */
	void shoutNew();

	/* Free all memory allocated by a shout_t */
	void shoutFree();

	/* Returns a statically allocated string describing the last shout error
	 * to occur.  Only valid until the next libshout call on this shout_t */
	string getError();

	/* Return the error code (e.g. SHOUTERR_SOCKET) for this shout instance */
	int getErrno();

	/* returns SHOUTERR_CONNECTED or SHOUTERR_UNCONNECTED */
	int getConnected();

	/* Connection parameters */
	void setHost(string host);
	void setPort(unsigned short port);
	void setAgent(string agent);

	/* Authentication parameters */
	void setUser(string username);
	void setPassword(string password);

	/* Mount parameters */
	void setMount(string mount);

	/* Other parameters */
	void setName(string name); // obsolete
	void setUrl(string url); // obsolete
	void setGenre(string genre); // obsolete
	void setDescription(string description); // obsolete
	void setDumpfile(string dumpfile);

	void setAudioInfo(string name, string value);
	void setAudioInfoBitrate(string value);
	void setAudioInfoSamplerate(string value);
	void setAudioInfoChannels(string value);
	void setAudioInfoQuality(string value);

	/* takes a SHOUT_META_xxxx argument */
	void setMeta(string name, string value);
	void setPublic(unsigned int make_public);

	/* takes a SHOUT_FORMAT_xxxx argument */
	void setFormat(unsigned int format);
	void setFormatOgg();
	void setFormatMp3();
	void setFormatWebM();
	void setFormatWebMAudio();

	/* takes a SHOUT_PROTOCOL_xxxxx argument */
	void setProtocol(unsigned int protocol);
	void setProtocolHttp();
	void setProtocolXAudioCast();
	void setProtocolIcy();
	void setProtocolRoarAudio();

	/* Instructs libshout to use nonblocking I/O. Must be called before
	 * shout_open (no switching back and forth midstream at the moment). */
	void setNonblocking(unsigned int nonblocking);

	/* Opens a connection to the server.  All parameters must already be set */
	int shoutOpen();

	/* Closes a connection to the server */
	int shoutClose();

	/* Send data to the server, parsing it for format specific timing info */
	int shoutSend(const unsigned char *data, size_t len);

	/* return the number of bytes currently on the write queue (only makes sense in
	 * nonblocking mode). */
	ssize_t shoutQueuelen();

	/* Puts caller to sleep until it is time to send more data to the server */
	void shoutSync();

	/* Amount of time in ms caller should wait before sending again */
	int shoutDelay();

public:
	LibShout(ILogService *logSrv, IcecastClientConfig* config);
	virtual ~LibShout();

	void initializeShout();
	void startShout();
	void finilizeShout();

};

#endif // LibShout_h__
