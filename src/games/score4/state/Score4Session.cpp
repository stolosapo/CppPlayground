#include "Score4Session.h"

Score4Session::Score4Session(const int id, const char* hash) : id(id), hash(hash)
{
	players = 0;
	player_a = "";
	player_b = "";

	current_player = -1;
	finished = false;

	initTable();
}

Score4Session::~Score4Session()
{

}

void Score4Session::initTable()
{
	for (int x = 0; x < 7; ++x)
	{
		for (int y = 0; y < 6; ++y)
		{
			table[x][y] = -1;
		}
	}
}

const int Score4Session::getId() const
{
	return id;
}

const char* Score4Session::getHash() const
{
	return hash;
}

int Score4Session::getPlayers()
{
	return players;
}

string Score4Session::getPlayerA()
{
	return player_a;
}

string Score4Session::getPlayerB()
{
	return player_b;
}

int Score4Session::getCurrentPlayer()
{
	return current_player;
}

bool Score4Session::isFinished()
{
	return finished;
}

string Score4Session::getSerializedTable()
{
	string str_table = "";

	for (int x = 0; x < 7; ++x)
	{
		for (int y = 0; y < 6; ++y)
		{
			str_table += table[x][y];
		}
	}

	return str_table;
}