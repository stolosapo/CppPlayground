#include <iostream>
#include "menu/MainMenu.cpp"

using namespace std;

int main()
{
	MainMenu *menu = new MainMenu;
	menu->action();
}