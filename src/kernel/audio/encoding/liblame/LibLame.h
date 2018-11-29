#ifndef LibLame_h__
#define LibLame_h__

#include <string>

#ifdef LAME
#include <lame/lame.h>
#endif

using namespace std;

class LibLame
{
private:

#ifdef LAME
    lame_global_flags* lame;

    hip_t hipDecodeInit();
    void hipDecodeExit(hip_t hip);

    int hipDecode1Headers(hip_t hip, unsigned char*  mp3buf, size_t len, short pcm_l[], short pcm_r[], mp3data_struct* mp3data);
#endif

public:
	LibLame();
	virtual ~LibLame();

    void init();
    int initParams();
    void close();

    void id3tagInit();
    void id3tagV2Only();
    void id3tagSetYear(string year);
    void id3tagSetGenre(string genre);
    void id3tagSetArtist(string artist);
    void id3tagSetAlbum(string album);
    void id3tagSetTitle(string title);
    void id3tagSetTrack(string track);
    void id3tagSetComment(string comment);
    void id3tagSetAlbumArt(string albumArtPath);

    int getId3v1Tag(unsigned char* buffer, int size);
    int getId3v2Tag(unsigned char* buffer, int size);
    int getLameTagFrame(unsigned char* buffer, int size);

    void setDecodeOnly(bool enabled);
    void setInSamplerate(int samplerate);
    void setBWriteVbrTag(bool enabled);
    void setVBR(int vbr_mode);
    void setVBRq(int quality);
    void setVBRMeanBitrateKbps(int abr_bitrate);
    void setQuality(int quality);
    void setBrate(int cbr_bitrate);
    void setOutSamplerate(int rample_frequency);
    void setFindReplayGain(bool enabled);
    void setWriteId3tagAutomatic(bool enabled);

    int encodeFlush(unsigned char* mp3_buffer, int size);
    int encodeBufferInterleaved(short int* pcm_buffer, int num_samples, unsigned char* mp3_buffer, int mp3_buffer_size);

};

#endif // LibLame_h__