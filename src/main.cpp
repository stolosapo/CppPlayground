#include <iostream>
#include "json/JsonServiceFactory.h"

using namespace std;

int main()
{
	cout << "Hello World!" << endl;

	IJsonService* srv = JsonServiceFactory::create();
	srv->test();

}