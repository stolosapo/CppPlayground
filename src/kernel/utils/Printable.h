#ifndef Printable_h__
#define Printable_h__

class Printable
{
public:
	Printable() { };
	virtual ~Printable() { };

	virtual void print() = 0;
};

#endif // Printable_h__