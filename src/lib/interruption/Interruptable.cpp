#include "Interruptable.h"

#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

using namespace std;


Interruptable::Interruptable()
{
        ctrl_c_pressed = false;
}


Interruptable::~Interruptable()
{

}


void Interruptable::handler(int sig)
{
        write(0, "\nCtrl^C pressed in sig handler\n", 32);
	ctrl_c_pressed = true;
}


bool Interruptable::ctrlC_Interruption()
{
        return ctrl_c_pressed;
}


void Interruptable::setup()
{
        reset();

        struct sigaction sig_struct;
        // sig_struct.sa_handler = handler;
        sig_struct.sa_flags = 0;
        sigemptyset(&sig_struct.sa_mask);

        if (sigaction(SIGINT, &sig_struct, NULL) == -1)
        {
            cout << "Problem with sigaction" << endl;
            exit(1);
        }
}


void Interruptable::reset()
{
        ctrl_c_pressed = false;
}
