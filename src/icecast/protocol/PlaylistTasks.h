#ifndef PlaylistTasks_h__
#define PlaylistTasks_h__

#include "../NoiseStreamer.h"
#include "../audio/PlaylistAudioSource.h"
#include "../../kernel/task/TaskContext.h"

PlaylistAudioSource* playlist_audio_source(NoiseStreamer* client);

void* nss_playlist_audio_status(NoiseStreamer* client);
void* nss_playlist_now_playing(NoiseStreamer* client);
void* nss_playlist_preview_next(NoiseStreamer* client);
void* nss_playlist_preview_track(TaskContext* context, NoiseStreamer* client);
void* nss_playlist_search(TaskContext* context, NoiseStreamer* client);
void* nss_playlist_history(TaskContext* context, NoiseStreamer* client);
void* nss_playlist_next_track(NoiseStreamer* client);
void* nss_playlist_request_track(TaskContext* context, NoiseStreamer* client);
void* nss_playlist_stats_genre(NoiseStreamer* client);
void* nss_playlist_stats_artist(NoiseStreamer* client);

#endif // PlaylistTasks_h__
