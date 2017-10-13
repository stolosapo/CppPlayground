#ifndef Mp3Parser_h__
#define Mp3Parser_h__

#include <fstream>

using namespace std;

class Mp3Parser
{
private:
	/* these values for bitrates and frequencies might come in useful */
	static const unsigned int bitrate[];
	static const unsigned int freq[];

	void parseDetails(ifstream &file);

public:
	Mp3Parser();
	virtual ~Mp3Parser();

	void parse();
	char* loadFile(const char* filename);

};

#endif // Mp3Parser_h__
