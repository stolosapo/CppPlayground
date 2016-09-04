#include <iostream>
#include "KubeTracer.h"

using namespace std;


const char* KubeTracer::UP_STR = "U";
const char* KubeTracer::ANTI_UP_STR = "U'";
const char* KubeTracer::DOUBLE_UP_STR = "U2";
const char* KubeTracer::DOWN_STR = "D";
const char* KubeTracer::ANTI_DOWN_STR = "D'";
const char* KubeTracer::DOUBLE_DOWN_STR = "D2";
const char* KubeTracer::LEFT_STR = "L";
const char* KubeTracer::ANTI_LEFT_STR = "L'";
const char* KubeTracer::DOUBLE_LEFT_STR = "L2";
const char* KubeTracer::RIGHT_STR = "R";
const char* KubeTracer::ANTI_RIGHT_STR = "R'";
const char* KubeTracer::DOUBLE_RIGHT_STR = "R2";
const char* KubeTracer::FRONT_STR = "F";
const char* KubeTracer::ANTI_FRONT_STR = "F'";
const char* KubeTracer::DOUBLE_FRONT_STR = "F2";
const char* KubeTracer::BACK_STR = "B";
const char* KubeTracer::ANTI_BACK_STR = "B'";
const char* KubeTracer::DOUBLE_BACK_STR = "B2";
const char* KubeTracer::X_STR = "x";
const char* KubeTracer::ANTI_X_STR = "x'";
const char* KubeTracer::DOUBLE_X_STR = "x2";
const char* KubeTracer::Y_STR = "y";
const char* KubeTracer::ANTI_Y_STR = "y'";
const char* KubeTracer::DOUBLE_Y_STR = "y2";
const char* KubeTracer::Z_STR = "z";
const char* KubeTracer::ANTI_Z_STR = "z'";
const char* KubeTracer::DOUBLE_Z_STR = "z2";



KubeTracer::KubeTracer()
{

}

KubeTracer::~KubeTracer()
{
	vector<KubeTracer::Move>().swap(traces);
}


void KubeTracer::traceMove(KubeTracer::Move move)
{
	traces.push_back(move);
}



string KubeTracer::convertToString(KubeTracer::Move move)
{
	switch (move)
	{
		case KubeTracer::UP:
			return KubeTracer::UP_STR;

		case KubeTracer::ANTI_UP:
			return KubeTracer::ANTI_UP_STR;

		case KubeTracer::DOUBLE_UP:
			return KubeTracer::DOUBLE_UP_STR;

		case KubeTracer::DOWN:
			return KubeTracer::DOWN_STR;

		case KubeTracer::ANTI_DOWN:
			return KubeTracer::ANTI_DOWN_STR;

		case KubeTracer::DOUBLE_DOWN:
			return KubeTracer::DOUBLE_DOWN_STR;

		case KubeTracer::LEFT:
			return KubeTracer::LEFT_STR;

		case KubeTracer::ANTI_LEFT:
			return KubeTracer::ANTI_LEFT_STR;

		case KubeTracer::DOUBLE_LEFT:
			return KubeTracer::DOUBLE_LEFT_STR;

		case KubeTracer::RIGHT:
			return KubeTracer::RIGHT_STR;

		case KubeTracer::ANTI_RIGHT:
			return KubeTracer::ANTI_RIGHT_STR;

		case KubeTracer::DOUBLE_RIGHT:
			return KubeTracer::DOUBLE_RIGHT_STR;

		case KubeTracer::FRONT:
			return KubeTracer::FRONT_STR;

		case KubeTracer::ANTI_FRONT:
			return KubeTracer::ANTI_FRONT_STR;

		case KubeTracer::DOUBLE_FRONT:
			return KubeTracer::DOUBLE_FRONT_STR;

		case KubeTracer::BACK:
			return KubeTracer::BACK_STR;

		case KubeTracer::ANTI_BACK:
			return KubeTracer::ANTI_BACK_STR;

		case KubeTracer::DOUBLE_BACK:
			return KubeTracer::DOUBLE_BACK_STR;

		case KubeTracer::X:
			return KubeTracer::X_STR;

		case KubeTracer::ANTI_X:
			return KubeTracer::ANTI_X_STR;

		case KubeTracer::DOUBLE_X:
			return KubeTracer::DOUBLE_X_STR;

		case KubeTracer::Y:
			return KubeTracer::Y_STR;

		case KubeTracer::ANTI_Y:
			return KubeTracer::ANTI_Y_STR;

		case KubeTracer::DOUBLE_Y:
			return KubeTracer::DOUBLE_Y_STR;

		case KubeTracer::Z:
			return KubeTracer::Z_STR;

		case KubeTracer::ANTI_Z:
			return KubeTracer::ANTI_Z_STR;

		case KubeTracer::DOUBLE_Z:
			return KubeTracer::DOUBLE_Z_STR;
	}
}


string KubeTracer::convertToString()
{
	int size = traces.size();
	string trace = "";

	for (int i = 0; i < size; ++i)
	{
		bool isLast = i == size - 1;

		trace.append(convertToString(traces[i]));

		if (!isLast)
		{
			trace.append(", ");
		}
	}

	return trace;
}


KubeTracer::Move KubeTracer::convertToMove(string move)
{
	if (move == KubeTracer::UP_STR)
	{
		return KubeTracer::UP;
	}

	else if (move == KubeTracer::ANTI_UP_STR)
	{
		return KubeTracer::ANTI_UP;
	}

	else if (move == KubeTracer::DOUBLE_UP_STR)
	{
		return KubeTracer::DOUBLE_UP;
	}

	else if (move == KubeTracer::DOWN_STR)
	{
		return KubeTracer::DOWN;
	}

	else if (move == KubeTracer::ANTI_DOWN_STR)
	{
		return KubeTracer::ANTI_DOWN;
	}

	else if (move == KubeTracer::DOUBLE_DOWN_STR)
	{
		return KubeTracer::DOUBLE_DOWN;
	}

	else if (move == KubeTracer::LEFT_STR)
	{
		return KubeTracer::LEFT;
	}

	else if (move == KubeTracer::ANTI_LEFT_STR)
	{
		return KubeTracer::ANTI_LEFT;
	}

	else if (move == KubeTracer::DOUBLE_LEFT_STR)
	{
		return KubeTracer::DOUBLE_LEFT;
	}

	else if (move == KubeTracer::RIGHT_STR)
	{
		return KubeTracer::RIGHT;
	}

	else if (move == KubeTracer::ANTI_RIGHT_STR)
	{
		return KubeTracer::ANTI_RIGHT;
	}

	else if (move == KubeTracer::DOUBLE_RIGHT_STR)
	{
		return KubeTracer::DOUBLE_RIGHT;
	}

	else if (move == KubeTracer::FRONT_STR)
	{
		return KubeTracer::FRONT;
	}

	else if (move == KubeTracer::ANTI_FRONT_STR)
	{
		return KubeTracer::ANTI_FRONT;
	}

	else if (move == KubeTracer::DOUBLE_FRONT_STR)
	{
		return KubeTracer::DOUBLE_FRONT;
	}

	else if (move == KubeTracer::BACK_STR)
	{
		return KubeTracer::BACK;
	}

	else if (move == KubeTracer::ANTI_BACK_STR)
	{
		return KubeTracer::ANTI_BACK;
	}

	else if (move == KubeTracer::DOUBLE_BACK_STR)
	{
		return KubeTracer::DOUBLE_BACK;
	}

	else if (move == KubeTracer::X_STR)
	{
		return KubeTracer::X;
	}

	else if (move == KubeTracer::ANTI_X_STR)
	{
		return KubeTracer::ANTI_X;
	}

	else if (move == KubeTracer::DOUBLE_X_STR)
	{
		return KubeTracer::DOUBLE_X;
	}

	else if (move == KubeTracer::Y_STR)
	{
		return KubeTracer::Y;
	}

	else if (move == KubeTracer::ANTI_Y_STR)
	{
		return KubeTracer::ANTI_Y;
	}

	else if (move == KubeTracer::DOUBLE_Y_STR)
	{
		return KubeTracer::DOUBLE_Y;
	}

	else if (move == KubeTracer::Z_STR)
	{
		return KubeTracer::Z;
	}

	else if (move == KubeTracer::ANTI_Z_STR)
	{
		return KubeTracer::ANTI_Z;
	}

	else if (move == KubeTracer::DOUBLE_Z_STR)
	{
		return KubeTracer::DOUBLE_Z;
	}
}