#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FigletHeader.h"

FigletHeader::FigletHeader()
{

}

FigletHeader::~FigletHeader()
{
	headers.clear();
	vector<string>().swap(headers);
}

int FigletHeader::getRandomNumber()
{
	int num;
	int size = headers.size();

	/* initialize random seed: */
  	srand (time(NULL));

  	/* generate secret number between 1 and 10: */
  	num = rand() % size;

  	return num;
}

string FigletHeader::getRandomHeader()
{
	if (headers.size() == 0)
	{
		fillHeaders();
	}

	return headers[getRandomNumber()];
}

string FigletHeader::getHeader(int index)
{
	if (headers.size() == 0)
	{
		fillHeaders();
	}
	
	if (index >= headers.size())
	{
		index = 0;
	}

	return headers[index];
}
