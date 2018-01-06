#ifndef Score4Session_h__
#define Score4Session_h__

#include <string>

using namespace std;

class Score4Session
{
private:
	const int id;
	const char* hash;
	
	int players;
	string player_a;
	string player_b;

	int current_player;

	bool finished;

	int table[7][6];

	void initTable();

public:
	Score4Session(const int id, const char* hash);
	virtual ~Score4Session();

	const int getId() const;
	const char* getHash() const;

	int getPlayers();
	string getPlayerA();
	string getPlayerB();

	int getCurrentPlayer();
	bool isFinished();

	string getSerializedTable();

};

#endif // Score4Session_h__
