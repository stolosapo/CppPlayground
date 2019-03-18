#ifndef Score4State_h__
#define Score4State_h__

#include <string>
#include <map>

#include "Score4Session.h"

using namespace std;

class Score4State
{
private:
	map<string, Score4Session*> sessions;

public:
	Score4State();
	virtual ~Score4State();

	void addSession(string hash, Score4Session* session);
	Score4Session* getSession(string hash);

};

#endif // Score4State_h__
