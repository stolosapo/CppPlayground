#ifndef NoiseStreamerAgentTasks_h__
#define NoiseStreamerAgentTasks_h__


/*

help

agent-status (active connections, uptime, version ..)
audio-status (info about audio source)

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

now
preview (next)
preview-track X

stop
start
pause
resume
next

*/


/* Status tasks */
void* nss_agent_status(void* context);
void* nss_audio_status(void* context);
void* nss_shout_status(void* context);


/* Navigation tasks */
void* nss_start_client(void* agent);
void* nss_start(void* context);
void* nss_stop(void* context);
void* nss_pause(void* context);
void* nss_resume(void* context);
void* nss_next_track(void* context);


/* Playlist Tasks */
void* nss_now_playing(void* context);
void* nss_preview_next(void* context);
void* nss_preview_track(void* context);
void* nss_search(void* context);


/* History Tasks */
void* nss_history(void* context);


/* Request Tasks */
void* nss_request_track(void* context);


/* Statistic tasks */
void* nss_stats_genre(void* context);
void* nss_stats_artist(void* context);


#endif // NoiseStreamerAgentTasks_h__
