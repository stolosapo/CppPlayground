#ifndef Property_h__
#define Property_h__

#include <iostream>
#include <string>

using namespace std;

class Property
{
public:
	enum Type
	{
		INT = 0,

		LONG = 1,

		DOUBLE = 2,

		STRING = 3,

		BOOL = 4,

		OBJECT = 5,

		COLLECTION_INT = 6

		// COLLECTION_LONG = 7,

		// COLLECTION_DOUBLE = 8,

		// COLLECTION_STRING = 9,

		// COLLECTION_BOOL = 8,

		// COLLECTION_OBJECT = 9
	};

	Property(string name, Type type);
	virtual ~Property();

	string getName();
	Type getType();

private:
	string name;
	Type type;

};
#endif // Property_h__
