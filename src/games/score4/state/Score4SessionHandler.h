#ifndef Score4SessionHandler_h__
#define Score4SessionHandler_h__

#include <string>

#include "Score4Session.h"

using namespace std;

class Score4SessionHandler
{
private:
	Score4Session* session;

public:
	Score4SessionHandler(Score4Session* session);
	virtual ~Score4SessionHandler();

	static Score4Session* createNewSession();

	void addPlayer(string name);
	void makeMove(string player, int input);
};

#endif // Score4SessionHandler_h__
