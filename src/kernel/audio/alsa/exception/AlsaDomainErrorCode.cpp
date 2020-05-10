#include "AlsaDomainErrorCode.h"


const DomainErrorCode AlsaDomainErrorCode::ALS0001 = DomainErrorCode("ALS0001", "ALSA feature is not enabled, try to pass the WITH_ALSA=1 param when Make.");

const DomainErrorCode AlsaDomainErrorCode::ALS0002 = DomainErrorCode("ALS0002", "Cannot open audio device %s (%s)");
const DomainErrorCode AlsaDomainErrorCode::ALS0003 = DomainErrorCode("ALS0003", "Cannot allocate hardware parameter structure (%s)");
const DomainErrorCode AlsaDomainErrorCode::ALS0004 = DomainErrorCode("ALS0004", "Cannot initialize hardware parameter structure (%s)");
const DomainErrorCode AlsaDomainErrorCode::ALS0005 = DomainErrorCode("ALS0005", "Cannot set access type (%s)");
const DomainErrorCode AlsaDomainErrorCode::ALS0006 = DomainErrorCode("ALS0006", "Cannot set sample format (%s)");
const DomainErrorCode AlsaDomainErrorCode::ALS0007 = DomainErrorCode("ALS0007", "Cannot set sample rate (%s)");
const DomainErrorCode AlsaDomainErrorCode::ALS0008 = DomainErrorCode("ALS0008", "Cannot set channel count (%s)");
const DomainErrorCode AlsaDomainErrorCode::ALS0009 = DomainErrorCode("ALS0009", "Cannot set parameters (%s)");

const DomainErrorCode AlsaDomainErrorCode::ALS0010 = DomainErrorCode("ALS0010", "Cannot allocate software parameters structure (%s)");
const DomainErrorCode AlsaDomainErrorCode::ALS0011 = DomainErrorCode("ALS0011", "Cannot initialize software parameters structure (%s)");
const DomainErrorCode AlsaDomainErrorCode::ALS0012 = DomainErrorCode("ALS0012", "Cannot set minimum available count (%s)");
const DomainErrorCode AlsaDomainErrorCode::ALS0013 = DomainErrorCode("ALS0013", "Cannot set start mode (%s)");
const DomainErrorCode AlsaDomainErrorCode::ALS0014 = DomainErrorCode("ALS0014", "Cannot set software parameters (%s)");
const DomainErrorCode AlsaDomainErrorCode::ALS0015 = DomainErrorCode("ALS0015", "Cannot prepare audio interface for use (%s)");
const DomainErrorCode AlsaDomainErrorCode::ALS0016 = DomainErrorCode("ALS0016", "Read from audio interface failed");



AlsaDomainErrorCode::AlsaDomainErrorCode()
{

}

AlsaDomainErrorCode::~AlsaDomainErrorCode()
{

}
