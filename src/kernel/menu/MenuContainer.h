#ifndef MenuContainer_h__
#define MenuContainer_h__

#include <iostream>
#include <string>
#include <vector>

#include "MenuItem.h"
#include "../log/ILogService.h"
#include "../interruption/SignalService.h"


using namespace std;

class MenuContainer : public MenuItem
{
private:
	static const int DEFAULT_EXIT_CODE = 0;

	string question;
	int selection;
	int exitCode;
	bool useOptions;
	bool continueQuestion;

    vector<MenuItem*> items;

    void tree(int depth);

public:
	MenuContainer(int id, string name, string title);
	virtual ~MenuContainer();

	int getSize();
	string getQuestion();
	bool getContinueQuestion();
	int getSelection();
	int getExitCode();
	bool getUseOptions();

	virtual void action();
	virtual string identify();
    void tree();

protected:
	ILogService *logSrv;
	SignalService *sigSrv;

	void setUseOptions(bool useOptions);
	void setQuestion(string question);
	void setContinueQuestion(bool continueQuestion);

	void addMenuItem(MenuItem *menuItem);
    void clear();

	int getMaxDisplaySize();

	virtual MenuItem *findMenuItem();
    virtual MenuItem* findMenuItemByName(string name);
	virtual int promptQuestion();
	virtual bool promptContinueQuestion();
	virtual void showOptions();

	virtual string getHeader() = 0;
	virtual void fillOptions() = 0;
};

#endif // MenuContainer_h__
