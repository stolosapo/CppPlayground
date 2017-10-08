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
	int setHost(string host);
	int setPort(unsigned short port);
	int setAgent(string agent);

	/* Authentication parameters */
	int setUser(string username);
	int setPassword(string password);

	/* Mount parameters */
	int setMount(string mount);

	/* Other parameters */
	int setName(string name); // obsolete
	int setUrl(string url); // obsolete
	int setGenre(string genre); // obsolete
	int setDescription(string description); // obsolete
	int setDumpfile(string dumpfile);
	int setAudioInfo(string name, string value);

	/* takes a SHOUT_META_xxxx argument */
	int setMeta(string name, string value);
	int setPublic(unsigned int make_public);

	/* takes a SHOUT_FORMAT_xxxx argument */
	int setFormat(unsigned int format);

	/* takes a SHOUT_PROTOCOL_xxxxx argument */
	int setProtocol(unsigned int protocol);

	/* Instructs libshout to use nonblocking I/O. Must be called before
	 * shout_open (no switching back and forth midstream at the moment). */
	int setNonblocking(unsigned int nonblocking);

	/* Opens a connection to the server.  All parameters must already be set */
	int shoutOpen();

	/* Closes a connection to the server */
	int shoutClose();

	/* Send data to the server, parsing it for format specific timing info */
	int shoutSend(const unsigned char *data, size_t len);

public:
	LibShout(ILogService *logSrv, IcecastClientConfig* config);
	virtual ~LibShout();

	void initializeShout();

};

#endif // LibShout_h__