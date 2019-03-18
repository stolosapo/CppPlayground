#include <iostream>
#include <string>
#include "../kernel/utils/FigletHeader.h"

using namespace std;

class MainMenuHeader : public FigletHeader
{
public:
	MainMenuHeader() : FigletHeader()
	{

	}

	virtual ~MainMenuHeader()
	{

	}

private:
	string colossal()
	{
		return "\n"
			"88888888888 8888888888 888    d8P    \n" 
			"    888     888        888   d8P     \n" 
			"    888     888        888  d8P      \n" 
			"    888     8888888    888d88K       \n" 
			"    888     888        8888888b      \n" 
			"    888     888        888  Y88b     \n" 
			"    888  d8b888     d8b888   Y88b d8b\n" 
			"    888  Y8P888     Y8P888    Y88bY8P\n";
	}

	string block()
	{
		return "\n"
			"_|_|_|_|_|  _|_|_|_|  _|    _| \n" 
			"    _|      _|        _|  _|   \n"
			"    _|      _|_|_|    _|_|     \n"
			"    _|      _|        _|  _|   \n"
			"    _|      _|        _|    _| \n";
	}

	string dotmatrix()
	{
		return "\n"
			" _  _  _  _  _           _  _  _  _  _           _           _        \n"  
			"(_)(_)(_)(_)(_)         (_)(_)(_)(_)(_)         (_)       _ (_)       \n"  
			"      (_)               (_)                     (_)    _ (_)          \n"  
			"      (_)               (_) _  _                (_) _ (_)             \n"  
			"      (_)               (_)(_)(_)               (_)(_) _              \n"  
			"      (_)        _  _   (_)              _  _   (_)   (_) _      _  _ \n"  
			"      (_)       (_)(_)  (_)             (_)(_)  (_)      (_) _  (_)(_)\n"  
			"      (_)       (_)(_)  (_)             (_)(_)  (_)         (_) (_)(_)\n";
	}

protected:
	virtual void fillHeaders()
	{
		headers.push_back(colossal());
		headers.push_back(block());
		headers.push_back(dotmatrix());
	}

};
