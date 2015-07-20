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
	string question;
	int selection;
	int exitCode;
	bool useOptions;

public:
	Container(int id, string name, string caption, int exitCode);
	virtual ~Container();
	
	int getId();
	string getName();
	string getCaption();
	bool getEnable();
	string getQuestion();
	int getSelection();
	int getExitCode();
	bool getUseOptions();

	void run();

protected:
	void setEnable(bool enable);
	void setUseOptions(bool useOptions);
	void setQuestion(string question);

	void clearScreen();
	int promptQuestion();

	virtual void execute() = 0;
	virtual void showOptions() = 0;
};

#endif // Container_h__