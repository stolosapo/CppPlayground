#ifndef NoiseStreamerAgentTasks_h__
#define NoiseStreamerAgentTasks_h__


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

stats-genre
stats-artist

stop
start
pause
resume
next

*/


/* Status tasks */
void* nss_agent_status(void* agent);


/* Navigation tasks */
void* nss_now_playing(void* agent);
void* nss_start_client(void* agent);
void* nss_start(void* agent);
void* nss_stop_playing(void* agent);
void* nss_pause(void* agent);
void* nss_resume(void* agent);
void* nss_next_track(void* agent);


/* Statistic tasks */
void* nss_stats_genre(void* agent);
void* nss_stats_artist(void* agent);


#endif // NoiseStreamerAgentTasks_h__
