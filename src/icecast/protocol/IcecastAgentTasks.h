#ifndef IcecastAgentTasks_h__
#define IcecastAgentTasks_h__


void* icecast_start(void* icecast);
void* icecast_next_track(void* data);
void* icecast_stop_playing(void* data);


#endif // IcecastAgentTasks_h__
