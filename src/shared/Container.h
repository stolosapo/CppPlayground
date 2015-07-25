#ifndef Container_h__
#define Container_h__

#include <iostream>
#include <string>
#include "../log/ILogService.h"
#include "../menu/MenuItem.h"


using namespace std;

class Container : public MenuItem
{
private:
	static const int DEFAULT_EXIT_CODE = 0;

	int size;
	string question;
	int selection;
	int exitCode;
	bool useOptions;

	ILogService *logSrv;
	MenuItem **menuItems;

public:
	Container(int id, string name, string title, const int size);
	virtual ~Container();
	
	int getSize();
	string getQuestion();
	int getSelection();
	int getExitCode();
	bool getUseOptions();

	virtual void action();
	virtual string identify();

protected:

	void setUseOptions(bool useOptions);
	void setQuestion(string question);

	void addMenuItem(int index, MenuItem *menuItem);
	
	virtual MenuItem *findMenuItem();
	virtual int promptQuestion();
	virtual void showOptions();

	virtual void execute(int menuItemId) = 0;
	virtual void fillOptions() = 0;
};

#endif // Container_h__