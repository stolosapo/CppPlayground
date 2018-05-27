#ifndef IcecastAgentTasks_h__
#define IcecastAgentTasks_h__


/*

help

agent-status (active connections, uptime, version ..)

shout-status (errors, version ..)
shout-config

playlist-info (number of tracks, name)
playlist-load-metadata
playlist-show-all-artists
playlist-show-all-genre
playlist-search-artist "XXX"
playlist-search-album "XXX"
playlist-search-track "XXX"
playlist-search-genre "XXX"

history-info (number of tracks)
history-show-last X

request-track X
request-list

*/

void* icecast_agent_status(void* agent);

void* icecast_now_playing(void* agent);

void* icecast_start(void* agent);
void* icecast_next_track(void* agent);
void* icecast_stop_playing(void* agent);


#endif // IcecastAgentTasks_h__
