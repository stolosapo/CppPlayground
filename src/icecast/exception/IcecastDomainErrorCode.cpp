#include "IcecastDomainErrorCode.h"


const DomainErrorCode IcecastDomainErrorCode::ICS0001 = DomainErrorCode("ICS0001", "Icecast feature is not enabled, try to pass the WITH_ICECAST=1 param when Make.");

const DomainErrorCode IcecastDomainErrorCode::ICS0002 = DomainErrorCode("ICS0002", "Could not allocate shout_t");
const DomainErrorCode IcecastDomainErrorCode::ICS0003 = DomainErrorCode("ICS0003", "Error setting hostname: '%s'");
const DomainErrorCode IcecastDomainErrorCode::ICS0004 = DomainErrorCode("ICS0004", "Error setting port: '%s'");
const DomainErrorCode IcecastDomainErrorCode::ICS0005 = DomainErrorCode("ICS0005", "Error setting agent: '%s'");
const DomainErrorCode IcecastDomainErrorCode::ICS0006 = DomainErrorCode("ICS0006", "Error setting username: '%s'");
const DomainErrorCode IcecastDomainErrorCode::ICS0007 = DomainErrorCode("ICS0007", "Error setting password: '%s'");
const DomainErrorCode IcecastDomainErrorCode::ICS0008 = DomainErrorCode("ICS0008", "Error setting mountpoint: '%s'");
const DomainErrorCode IcecastDomainErrorCode::ICS0009 = DomainErrorCode("ICS0009", "Error setting name: '%s'");
const DomainErrorCode IcecastDomainErrorCode::ICS0010 = DomainErrorCode("ICS0010", "Error setting url: '%s'");
const DomainErrorCode IcecastDomainErrorCode::ICS0011 = DomainErrorCode("ICS0011", "Error setting genre: '%s'");
const DomainErrorCode IcecastDomainErrorCode::ICS0012 = DomainErrorCode("ICS0012", "Error setting description: '%s'");
const DomainErrorCode IcecastDomainErrorCode::ICS0013 = DomainErrorCode("ICS0013", "Error setting dumpfile: '%s'");
const DomainErrorCode IcecastDomainErrorCode::ICS0014 = DomainErrorCode("ICS0014", "Error setting audio data: '%s'");
const DomainErrorCode IcecastDomainErrorCode::ICS0015 = DomainErrorCode("ICS0015", "Error setting metadata: '%s'");
const DomainErrorCode IcecastDomainErrorCode::ICS0016 = DomainErrorCode("ICS0016", "Error setting public: '%s'");
const DomainErrorCode IcecastDomainErrorCode::ICS0017 = DomainErrorCode("ICS0017", "Error setting format: '%s'");
const DomainErrorCode IcecastDomainErrorCode::ICS0018 = DomainErrorCode("ICS0018", "Error setting protocol: '%s'");
const DomainErrorCode IcecastDomainErrorCode::ICS0019 = DomainErrorCode("ICS0019", "Error setting non-blocking: '%s'");

const DomainErrorCode IcecastDomainErrorCode::ICS0020 = DomainErrorCode("ICS0020", "Error connecting: '%s'");

const DomainErrorCode IcecastDomainErrorCode::ICS0021 = DomainErrorCode("ICS0021", "ALSA feature is not enabled, try to pass the WITH_ALSA=1 param when Make.");

const DomainErrorCode IcecastDomainErrorCode::ICS0022 = DomainErrorCode("ICS0022", "Please specify playlist strategy (SIMPLE, RANDOM, RANDOM_ONCE)");

const DomainErrorCode IcecastDomainErrorCode::ICS0023 = DomainErrorCode("ICS0023", "Maximum of retries reached. Give up..");


IcecastDomainErrorCode::IcecastDomainErrorCode()
{

}

IcecastDomainErrorCode::~IcecastDomainErrorCode()
{

}
