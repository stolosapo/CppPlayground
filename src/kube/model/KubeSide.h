#ifndef KubeSide_h__
#define KubeSide_h__

class KubeSide
{
public:
	enum Color
	{
		MAIN = 0,

		MAIN_RIGHT = 1,

		MAIN_BACK = 2,

		MAIN_LEFT = 3,

		MAIN_UP = 4,

		MAIN_DOWN = 5
	};

	KubeSide();
	virtual ~KubeSide();

	Color** getTiles();
	Color getMainColor();

	void setTile(int row, int col, Color color);

private:
	Color **tiles;

};



#endif // KubeSide_h__