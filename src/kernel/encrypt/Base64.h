#ifndef Base64_h__
#define Base64_h__

#include <string>

using namespace std;

class Base64 
{
private:
	static const string BASE64_CHARS;

	static inline bool isBase64(unsigned char c);

public:	
	static string encode(unsigned char const* , unsigned int len);
	static string decode(std::string const& s);
};

#endif // Base64_h__