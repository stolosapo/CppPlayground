#include "Score4State.h"

Score4State::Score4State()
{

}

Score4State::~Score4State()
{
	/* Clear sessions*/
	for (map<string, Score4Session*>::iterator it = sessions.begin(); 
		it != sessions.end(); 
		++it)
	{
		delete it->second;
	}

	sessions.clear();
}

void Score4State::addSession(string hash, Score4Session* session)
{
	sessions[hash] = session;
}

Score4Session* Score4State::getSession(string hash)
{
	return sessions.find(hash)->second;
}