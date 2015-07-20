#ifndef Container_h__
#define Container_h__

#include <iostream>
#include <string>


using namespace std;

class Container
{
private:
	int id;
	string name;
	string caption;
	bool enable;

public:
	Container();
	virtual ~Container();
	
	int getId();
	void setId(int id);

	string getName();
	void setName(string name);

	string getCaption();
	void setCaption(string caption);

	bool getEnable();
	void setEnable(bool enable);

	void run();
	void execute() = 0;
};

#endif // Container_h__