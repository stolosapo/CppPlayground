#include "NoiseStreamerDomainErrorCode.h"


const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0001 = DomainErrorCode("NSS0001", "NoiseStremer feature is not enabled, try to pass the WITH_ICECAST=1 param when Make.");

const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0002 = DomainErrorCode("NSS0002", "Could not allocate shout_t");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0003 = DomainErrorCode("NSS0003", "Error setting hostname: '%s'");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0004 = DomainErrorCode("NSS0004", "Error setting port: '%s'");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0005 = DomainErrorCode("NSS0005", "Error setting agent: '%s'");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0006 = DomainErrorCode("NSS0006", "Error setting username: '%s'");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0007 = DomainErrorCode("NSS0007", "Error setting password: '%s'");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0008 = DomainErrorCode("NSS0008", "Error setting mountpoint: '%s'");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0009 = DomainErrorCode("NSS0009", "Error setting name: '%s'");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0010 = DomainErrorCode("NSS0010", "Error setting url: '%s'");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0011 = DomainErrorCode("NSS0011", "Error setting genre: '%s'");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0012 = DomainErrorCode("NSS0012", "Error setting description: '%s'");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0013 = DomainErrorCode("NSS0013", "Error setting dumpfile: '%s'");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0014 = DomainErrorCode("NSS0014", "Error setting audio data: '%s'");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0015 = DomainErrorCode("NSS0015", "Error setting metadata: '%s'");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0016 = DomainErrorCode("NSS0016", "Error setting public: '%s'");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0017 = DomainErrorCode("NSS0017", "Error setting format: '%s'");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0018 = DomainErrorCode("NSS0018", "Error setting protocol: '%s'");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0019 = DomainErrorCode("NSS0019", "Error setting non-blocking: '%s'");

const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0020 = DomainErrorCode("NSS0020", "Error connecting: '%s'");

const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0021 = DomainErrorCode("NSS0021", "ALSA feature is not enabled, try to pass the WITH_ALSA=1 param when Make.");

const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0022 = DomainErrorCode("NSS0022", "Please specify playlist strategy (SIMPLE, RANDOM, RANDOM_ONCE)");

const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0023 = DomainErrorCode("NSS0023", "Maximum of error count reached. Give up..");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0024 = DomainErrorCode("NSS0024", "Libshout error occured. Playlist stopped");

const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0025 = DomainErrorCode("NSS0025", "NoiseStreamer is not running!");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0026 = DomainErrorCode("NSS0026", "Failed to reencode track '%s', no encode context found");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0027 = DomainErrorCode("NSS0027", "Incorrect requested track index");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0028 = DomainErrorCode("NSS0028", "NoiseStreamer is already running!");
const DomainErrorCode NoiseStreamerDomainErrorCode::NSS0029 = DomainErrorCode("NSS0029", "Libshout queue length threshold reached '%s'");


NoiseStreamerDomainErrorCode::NoiseStreamerDomainErrorCode()
{

}

NoiseStreamerDomainErrorCode::~NoiseStreamerDomainErrorCode()
{

}
