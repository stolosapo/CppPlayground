#ifndef LibShout_h__
#define LibShout_h__

#include <string>
#include "../config/IcecastClientConfig.h"
#include "../../kernel/log/ILogService.h"
#include "../../kernel/interruption/SignalService.h"

#ifdef ICECAST
#include <shout/shout.h>
#endif

using namespace std;

class LibShout
{
private:
	static const int MAX_RETRY_NUMBER = 10;

	int currentRetryNumber;

	ILogService *logSrv;
	SignalService* sigSrv;

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
	const char* getError();

	/* Return the error code (e.g. SHOUTERR_SOCKET) for this shout instance */
	int getErrno();

	/* returns SHOUTERR_CONNECTED or SHOUTERR_UNCONNECTED */
	int getConnected();
	bool isConnected();

	/* Connection parameters */
	void setHost(string host);
	string getHost();
	void setPort(unsigned short port);
	string getPort();

	void setAgent(string agent);

	/* Authentication parameters */
	void setUser(string username);
	void setPassword(string password);

	/* Mount parameters */
	void setMount(string mount);
	string getMount();

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

#ifdef ICECAST
	shout_metadata_t* createNewMetadata();
	void setMeta(shout_metadata_t* metadata);
	void addMeta(shout_metadata_t* metadata, string name, string value);
	void addMetaSong(shout_metadata_t* metadata, string song);
	void freeMetadata(shout_metadata_t* metadata);
#endif

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
	int shoutQueuelen();

	/* Puts caller to sleep until it is time to send more data to the server */
	void shoutSync();

	/* Amount of time in ms caller should wait before sending again */
	int shoutDelay();

	void logCurrentStatus(string mess);
	bool successLastAction(string mess);

	int currentTries();
	void incrementTries();
	void clearTries();
	bool maxTriesReached();

public:
	LibShout(ILogService *logSrv, SignalService* sigSrv, IcecastClientConfig* config);
	virtual ~LibShout();

	void initializeShout();
	void finilizeShout();

	void startShout();
	void restartShout();
	void streamFile(const char* filename, const char* trackMetadata);

};

#endif // LibShout_h__
