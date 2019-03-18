#include <iostream>
#include <string>

#include "../kernel/utils/FigletHeader.h"

using namespace std;

class SerializationHeader : public FigletHeader
{
public:
	SerializationHeader() : FigletHeader()
	{

	}

	virtual ~SerializationHeader()
	{

	}

private:
	string colossal()
	{
		return "\n"
			"  888888                         \n"
			"    \"88b                         \n"
			"     888                         \n"
			"     888.d8888b  .d88b. 88888b.  \n"
			"     88888K     d88\"\"88b888 \"88b \n"
			"     888\"Y8888b.888  888888  888 \n"
			"     88P     X88Y88..88P888  888 \n"
			"     888 88888P' \"Y88P\" 888  888 \n"
			"   .d88P                         \n"
			" .d88P\"                          \n"
			"888P\" \n";
	}

	string dotmatrix()
	{
		return "\n"
			"      _  _  _                                              \n"
			"     (_)(_)(_)                                             \n"
			"        (_)   _  _  _  _       _  _  _     _  _  _  _      \n"
			"        (_) _(_)(_)(_)(_)   _ (_)(_)(_) _ (_)(_)(_)(_)_    \n"
			"        (_)(_)_  _  _  _   (_)         (_)(_)        (_)   \n"
			" _      (_)  (_)(_)(_)(_)_ (_)         (_)(_)        (_)   \n"
			"(_)  _  (_)   _  _  _  _(_)(_) _  _  _ (_)(_)        (_)   \n"
			" (_)(_)(_)   (_)(_)(_)(_)     (_)(_)(_)   (_)        (_)   \n";
	}

protected:
	virtual void fillHeaders()
	{
		headers.push_back(colossal());
		headers.push_back(dotmatrix());
	}

};
