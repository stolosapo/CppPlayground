#ifndef MenuItem_h__
#define MenuItem_h__

#include <iostream>
#include <string>

using namespace std;

class MenuItem
{
private:
	int id;

	string name;
	string title;
	string description;

	bool enable;

public:
	MenuItem();
	virtual ~MenuItem();

	int getId();
	string getName();
	string getTitle();
	string getDescription();
	bool getEnable();

	void setId(int id);
	void setName(string name);
	void setTitle(string title);
	void setDescription(string description);
	void setEnable(bool enable);

	virtual void action();
	virtual void check();
	virtual string identify();

};

#endif // MenuItem_h__
