#ifndef AlsaCapture_h__
#define AlsaCapture_h__

#include <iostream>
#include <string>

using namespace std;

class AlsaCapture
{
public:
	AlsaCapture();
	virtual ~AlsaCapture();

        void capture();
};

#endif // AlsaCapture_h__
