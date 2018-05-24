#include "IcecastAgentTasks.h"

#include <iostream>

#include "../IcecastClient.h"
#include "../IcecastAgent.h"

using namespace std;

void* icecast_start(void* agent)
{
	IcecastAgent* a = (IcecastAgent*) agent;

	a->getIcecast()->action();

	cout << "Icecast action ended" << endl;
}

void* icecast_next_track(void* agent)
{
	IcecastAgent* a = (IcecastAgent*) agent;

	a->getIcecast()->nextTrack();
}

void* icecast_stop_playing(void* agent)
{
	IcecastAgent* a = (IcecastAgent*) agent;

	a->getIcecast()->stopPlaying();
}
