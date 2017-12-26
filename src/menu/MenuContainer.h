#ifndef MenuContainer_h__
#define MenuContainer_h__

#include <iostream>
#include <string>
#include "../kernel/log/ILogService.h"
#include "../menu/MenuItem.h"


using namespace std;

class MenuContainer : public MenuItem
{
private:
	static const int DEFAULT_EXIT_CODE = 0;

	int size;
	string question;
	int selection;
	int exitCode;
	bool useOptions;
	bool continueQuestion;

	MenuItem **menuItems;

public:
	MenuContainer(int id, string name, string title, const int size);
	virtual ~MenuContainer();

	int getSize();
	string getQuestion();
	bool getContinueQuestion();
	int getSelection();
	int getExitCode();
	bool getUseOptions();

	virtual void action();
	virtual string identify();

protected:
	ILogService *logSrv;

	void setUseOptions(bool useOptions);
	void setQuestion(string question);
	void setContinueQuestion(bool continueQuestion);

	void addMenuItem(int index, MenuItem *menuItem);

	int getMaxDisplaySize();

	virtual MenuItem *findMenuItem();
	virtual int promptQuestion();
	virtual bool promptContinueQuestion();
	virtual void showOptions();

	virtual string getHeader() = 0;
	virtual void fillOptions() = 0;
};

#endif // MenuContainer_h__
