#include "GpioMenuItem.h"
#include "GpioObject.h"

using namespace std;

GpioMenuItem::GpioMenuItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(1);

	this->setName("Test Gpio Connection");
	this->setTitle("Test Gpio Connection");
}

GpioMenuItem::~GpioMenuItem()
{
	
}

void GpioMenuItem::action()
{
	string inputstate;

	// create new GPIO object to be attached to  GPIO4
	GpioObject *gpio4 = new GpioObject("4");

	// create new GPIO object to be attached to  GPIO17
	GpioObject *gpio17 = new GpioObject("17");

	gpio4->export_gpio();	// export GPIO4
	gpio17->export_gpio();	// export GPIO17

	logSrv->info("GPIO pins exported");

    gpio4->setdir_gpio("out");	// GPIO4 set to output
	gpio17->setdir_gpio("in");	// GPIO17 set to input

	logSrv->info("Set GPIO pin directions");

	gpio4->unexport_gpio();		// unexport GPIO4
	gpio17->unexport_gpio();	// unexport GPIO17

	logSrv->info("GPIO pins unexported");

	delete gpio4;
	delete gpio17;
	
	logSrv->info("Deallocationg GPIO Objects");	
}