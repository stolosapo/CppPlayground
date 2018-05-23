#include "IcecastAgentTasks.h"

#include <iostream>

#include "../IcecastClient.h"

using namespace std;

void* icecast_start(void* icecast)
{
	IcecastClient* client = (IcecastClient*) icecast;

	client->action();
}

void* icecast_next_track(void* data)
{
	cout << "icecast_next_track" << endl;
}

void* icecast_stop_playing(void* data)
{
	cout << "icecast_stop_playing" << endl;
}