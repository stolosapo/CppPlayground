#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "GpioMenuItem.h"
#include "GpioObject.h"

using namespace std;


void sig_handler(int sig);

bool ctrl_c_pressed = false;


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
	ctrl_c_pressed = false;

	// struct sigaction sig_struct;
	// sig_struct.sa_handler = sig_handler;
	// sig_struct.sa_flags = 0;
	// sigemptyset(&sig_struct.sa_mask);

	// if (sigaction(SIGINT, &sig_struct, NULL) == -1) {
	//     logSrv->error("Problem with sigaction");
	//     exit(1);
	// }


	string inputstate;

	// create new GPIO object to be attached to  GPIO4
	GpioObject *gpio4 = new GpioObject("4");

	// create new GPIO object to be attached to  GPIO17
	GpioObject *gpio17 = new GpioObject("17");

	gpio4->export_gpio();	// export GPIO4
	gpio17->export_gpio();	// export GPIO17

	logSrv->info("GPIO pins exported");

	gpio4->setdir_gpio("out");	// GPIO4 set to output
	gpio17->setdir_gpio("out");	// GPIO17 set to input

	logSrv->info("Set GPIO pin directions");



	while(1)
	{
		// wait for 0.5 seconds
		usleep(500000);

		// read state of GPIO17 input pin
		gpio17->getval_gpio(inputstate);
		logSrv->info("Current input pin state is " + inputstate);

		// if input pin is at state "0" i.e. button pressed
		if(inputstate == "0")
		{
			logSrv->info("input pin state is Pressed. Will check input pin state again in 20ms ");

			usleep(20000);

			logSrv->info("Checking again .....");

			// checking again to ensure that state "0" is due to button press and not noise
			gpio17->getval_gpio(inputstate);

			if(inputstate == "0")
			{
				logSrv->info("input pin state is definitely Pressed. Turning LED ON");

				// turn LED ON
				gpio4->setval_gpio("1");

				logSrv->info(" Waiting until pin is unpressed.....");

				while (inputstate == "0")
				{
					gpio17->getval_gpio(inputstate);
				}

				logSrv->info("pin is unpressed");
			}
			else
			{
				logSrv->info("input pin state is definitely UnPressed. That was just noise.");
			}

		}
		gpio4->setval_gpio("0");


		if(ctrl_c_pressed)
		{
			logSrv->info("Ctrl^C Pressed");
			logSrv->info("GPIO pins unexported");

			gpio4->unexport_gpio();
			gpio17->unexport_gpio();

			logSrv->info("Deallocationg GPIO Objects");

			delete gpio4;
			gpio4 = 0;
			delete gpio17;
			gpio17 = 0;
			break;
		}

	}

	logSrv->info("Exiting.....");
}

void sig_handler(int sig)
{
	write(0, "nCtrl^C pressed in sig handlern", 32);
	ctrl_c_pressed = true;
}
