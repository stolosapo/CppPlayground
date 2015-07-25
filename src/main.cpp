#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include "log/LogServiceFactory.h"
#include "time/TimeServiceFactory.h"
#include "menu/MenuFactory.h"
#include "euler/EulerProblemContainer.h"
#include "menu/MainMenu.cpp"

using namespace std;

int main()
{
	MainMenu *menu = new MainMenu;
	menu->action();
}