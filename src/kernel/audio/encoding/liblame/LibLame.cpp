#include "LibLame.h"

LibLame::LibLame()
{
#ifdef LAME
    lame = NULL;
#endif
}

LibLame::~LibLame()
{
#ifdef LAME
    if (lame != NULL)
    {
        // delete lame;
        // lame = NULL;
    }
#endif
}

void LibLame::init()
{
#ifdef LAME
    lame = lame_init();
#endif
}

int LibLame::initParams()
{
#ifdef LAME
    int r = lame_init_params(lame);

    if (r == -1)
    {
        // throw exception: parameters failed to initialize properly in lame
    }

    return r;
#endif

    return -1;
}

void LibLame::close()
{
#ifdef LAME
    lame_close(lame);
#endif
}

void LibLame::id3tagInit()
{
#ifdef LAME
    id3tag_init(lame);
#endif
}

void LibLame::id3tagV2Only()
{
#ifdef LAME
    id3tag_v2_only(lame);
#endif
}

void LibLame::id3tagSetYear(string year)
{
#ifdef LAME
    id3tag_set_year(lame, year.c_str());
#endif
}

void LibLame::id3tagSetGenre(string genre)
{
#ifdef LAME
    id3tag_set_genre(lame, genre.c_str());
#endif
}

void LibLame::id3tagSetArtist(string artist)
{
#ifdef LAME
    id3tag_set_artist(lame, artist.c_str());
#endif
}

void LibLame::id3tagSetAlbum(string album)
{
#ifdef LAME
    id3tag_set_album(lame, album.c_str());
#endif
}

void LibLame::id3tagSetTitle(string title)
{
#ifdef LAME
    id3tag_set_title(lame, title.c_str());
#endif
}

void LibLame::id3tagSetTrack(string track)
{
#ifdef LAME
    id3tag_set_track(lame, track.c_str());
#endif
}

void LibLame::id3tagSetComment(string comment)
{
#ifdef LAME
    id3tag_set_comment(lame, comment.c_str());
#endif
}

void LibLame::id3tagSetAlbumArt(string albumArtPath)
{
#ifdef LAME
    // set_id3_albumart(lame, albumArtPath.c_str());
#endif
}

int LibLame::getId3v1Tag(unsigned char* buffer, int size)
{
#ifdef LAME
    return lame_get_id3v1_tag(lame, buffer, size);
#endif

    return -1;
}

int LibLame::getId3v2Tag(unsigned char* buffer, int size)
{
#ifdef LAME
    return lame_get_id3v2_tag(lame, buffer, size);
#endif

    return -1;
}

int LibLame::getLameTagFrame(unsigned char* buffer, int size)
{
#ifdef LAME
    return lame_get_lametag_frame(lame, buffer, size);
#endif

    return -1;
}

void LibLame::setDecodeOnly(bool enabled)
{
#ifdef LAME
    lame_set_decode_only(lame, (int) enabled);
#endif
}

void LibLame::setInSamplerate(int samplerate)
{
#ifdef LAME
    lame_set_in_samplerate(lame, samplerate);
#endif
}

void LibLame::setModeMono()
{
#ifdef LAME
    lame_set_mode(lame, MONO);
#endif
}

void LibLame::setModeJointStereo()
{
#ifdef LAME
    lame_set_mode(lame, JOINT_STEREO);
#endif
}

void LibLame::setNumChannels(int channels)
{
#ifdef LAME
    lame_set_num_channels(lame, channels);
#endif
}

void LibLame::setBWriteVbrTag(bool enabled)
{
#ifdef LAME
    lame_set_bWriteVbrTag(lame, enabled);
#endif
}

void LibLame::setVBR_ABR()
{
#ifdef LAME
    lame_set_VBR(lame, vbr_abr);
#endif
}

void LibLame::setVBR_OFF()
{
#ifdef LAME
    lame_set_VBR(lame, vbr_off);
#endif
}

void LibLame::setVBR_MTRH()
{
#ifdef LAME
    lame_set_VBR(lame, vbr_mtrh);
#endif
}

void LibLame::setVBRq(int quality)
{
#ifdef LAME
    lame_set_VBR_q(lame, quality);
#endif
}

void LibLame::setVBRMeanBitrateKbps(int abr_bitrate)
{
#ifdef LAME
    lame_set_VBR_mean_bitrate_kbps(lame, abr_bitrate);
#endif
}

void LibLame::setQuality(int quality)
{
#ifdef LAME
    lame_set_quality(lame, quality);
#endif
}

void LibLame::setBrate(int cbr_bitrate)
{
#ifdef LAME
    lame_set_brate(lame, cbr_bitrate);
#endif
}

void LibLame::setOutSamplerate(int rample_frequency)
{
#ifdef LAME
    lame_set_out_samplerate(lame, rample_frequency);
#endif
}

void LibLame::setFindReplayGain(bool enabled)
{
#ifdef LAME
    lame_set_findReplayGain(lame, (int) enabled);
#endif
}

void LibLame::setWriteId3tagAutomatic(bool enabled)
{
#ifdef LAME
    lame_set_write_id3tag_automatic(lame, (int) enabled);
#endif
}


#ifdef LAME

hip_t LibLame::hipDecodeInit()
{
    return hip_decode_init();
}

void LibLame::hipDecodeExit(hip_t hip)
{
    hip_decode_exit(hip);
}

int LibLame::hipDecode1Headers(hip_t hip, unsigned char*  mp3_buffer, size_t mp3_len, short pcm_l[], short pcm_r[], mp3data_struct* mp3data)
{
    return hip_decode1_headers(hip, mp3_buffer, mp3_len, pcm_l, pcm_r, mp3data);
}

#endif


int LibLame::encodeFlush(unsigned char* mp3_buffer, int size)
{
#ifdef LAME
    return lame_encode_flush(lame, mp3_buffer, size);
#endif

    return -1;
}

int LibLame::encodeBufferInterleaved(short int* pcm_buffer, int num_samples, unsigned char* mp3_buffer, int mp3_buffer_size)
{
#ifdef LAME
    return lame_encode_buffer_interleaved(lame, pcm_buffer, num_samples, mp3_buffer, mp3_buffer_size);
#endif

    return -1;
}
