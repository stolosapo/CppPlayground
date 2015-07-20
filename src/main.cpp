#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include "log/LogServiceFactory.h"
#include "time/TimeServiceFactory.h"
#include "menu/MenuFactory.h"
#include "euler/EulerProblemContainer.h"

using namespace std;

int main()
{
	MenuFactory* menuFactory = new MenuFactory;
	menuFactory->run();
}