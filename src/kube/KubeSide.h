#ifndef KubeSide_h__
#define KubeSide_h__

#include "../shared/Printable.h"

class KubeSide : public Printable
{
public:
	enum Color
	{
		MAIN = 0,

		FIRST = 1,

		SECOND = 2,

		THIRD = 3,

		FORTH = 4,

		FIFTH = 5
	};

	KubeSide();
	virtual ~KubeSide();

	virtual void print();

private:
	Color mainColor;

	Color tiles[3][3];

};



#endif // KubeSide_h__