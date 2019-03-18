#ifndef KubeTracer_h__
#define KubeTracer_h__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class KubeTracer
{
public:
	enum Move
	{
		UP = 0,

		ANTI_UP = 1,

		DOUBLE_UP = 2,

		DOWN = 3,

		ANTI_DOWN = 4,

		DOUBLE_DOWN = 5,

		LEFT = 6,

		ANTI_LEFT = 7,

		DOUBLE_LEFT = 8,

		RIGHT = 9,

		ANTI_RIGHT = 10,

		DOUBLE_RIGHT = 11,

		FRONT = 12,

		ANTI_FRONT = 13,

		DOUBLE_FRONT = 14,

		BACK = 15,

		ANTI_BACK = 16,

		DOUBLE_BACK = 17,

		X = 18,

		ANTI_X = 19,

		DOUBLE_X = 20,

		Y = 21,

		ANTI_Y = 22,

		DOUBLE_Y = 23,

		Z = 24,

		ANTI_Z = 25,

		DOUBLE_Z = 26,
	};

	static const char* UP_STR;
	static const char* ANTI_UP_STR;
	static const char* DOUBLE_UP_STR;
	static const char* DOWN_STR;
	static const char* ANTI_DOWN_STR;
	static const char* DOUBLE_DOWN_STR;
	static const char* LEFT_STR;
	static const char* ANTI_LEFT_STR;
	static const char* DOUBLE_LEFT_STR;
	static const char* RIGHT_STR;
	static const char* ANTI_RIGHT_STR;
	static const char* DOUBLE_RIGHT_STR;
	static const char* FRONT_STR;
	static const char* ANTI_FRONT_STR;
	static const char* DOUBLE_FRONT_STR;
	static const char* BACK_STR;
	static const char* ANTI_BACK_STR;
	static const char* DOUBLE_BACK_STR;
	static const char* X_STR;
	static const char* ANTI_X_STR;
	static const char* DOUBLE_X_STR;
	static const char* Y_STR;
	static const char* ANTI_Y_STR;
	static const char* DOUBLE_Y_STR;
	static const char* Z_STR;
	static const char* ANTI_Z_STR;
	static const char* DOUBLE_Z_STR;

	KubeTracer();
	virtual ~KubeTracer();

	void traceMove(Move move);
	string convertToString(Move move);
	string convertToString();
	Move convertToMove(string move);

private:
	vector<Move> traces;

	void optimize();

};

#endif // KubeTracer_h__