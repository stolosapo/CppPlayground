#include "SimpleAudioTagService.h"

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>

#include "../../exception/domain/DomainException.h"
#include "../../exception/domain/GeneralDomainErrorCode.h"

#include "../../utils/FileHelper.h"

using namespace std;

SimpleAudioTagService::SimpleAudioTagService() : AudioTagService()
{

}

SimpleAudioTagService::~SimpleAudioTagService()
{

}

AudioTag* SimpleAudioTagService::read(const char* filename)
{
    string title = FileHelper::filename(filename);

	return AudioTag::emptyWithTitle(title);
}
