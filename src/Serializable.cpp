#include <iostream>

class Serializable
{
public:
	virtual ~Serializable() { }
	virtual void toJson() { }
};