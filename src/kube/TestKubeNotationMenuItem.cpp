#include "TestKubeNotationMenuItem.h"
#include "KubeLoader.h"
#include "KubePrinter.h"
#include "KubeColorMapper.h"
#include "KubeNavigator.h"
#include "../shared/InOut.h"


void makeCross(KubeNavigator *nav, KubePrinter *printer);
void testNotation(KubeNavigator *nav, KubePrinter *printer);

void printMovesMenu(ILogService *logSrv);
bool makeTheMove(string moveToMake, KubeNavigator *nav);


TestKubeNotationMenuItem::TestKubeNotationMenuItem(ILogService *logSrv) : MenuItem()
{
	this->logSrv = logSrv;

	this->setId(1);

	this->setName("Test Kube Notation");
	this->setTitle("Test Kube Notation");
}

TestKubeNotationMenuItem::~TestKubeNotationMenuItem()
{
	
}

void TestKubeNotationMenuItem::action()
{
	InOut *in = new InOut;

	KubeLoader *loader = new KubeLoader;

	Kube *kube;
	kube = loader->load();

	KubeNavigator *nav = new KubeNavigator(kube);
	KubePrinter *printer = new KubePrinter(logSrv, kube);
	printer->printKube();


	string move = "";
	bool moveDone = false;
	while(1)
	{
		/* Print menu */
		printMovesMenu(logSrv);

		/* Read choise */
		move = in->inString();

		if (move == "q")
		{
			break;
		}

		/* Make move */
		moveDone = makeTheMove(move, nav);
		logSrv->printl("");

		if (moveDone)
		{
			logSrv->printl("Your move is: " + move);
		}
		else
		{
			logSrv->printl("Give valid choise!!");
		}

		logSrv->printl("");
		printer->printKube();
	}

}




void printMovesMenu(ILogService *logSrv)
{
	logSrv->printl("Up: (U, U', U2)");
	logSrv->printl("Down: (D, D', D2)");
	logSrv->printl("Left: (L, L', L2)");
	logSrv->printl("Right: (R, R', R2)");
	logSrv->printl("Front: (F, F', F2)");
	logSrv->printl("Back: (B, B', B2)");
	logSrv->printl("Rotate the cube like an R: (x, x', x2)");
	logSrv->printl("Rotate the cube like a U: (y, y', y2)");
	logSrv->printl("");

	logSrv->print("Choose one from the above or (q) from quit: ");	
}

bool makeTheMove(string moveToMake, KubeNavigator *nav)
{
	bool makeMove = true;

	if (moveToMake == "U") nav->up();
	else if (moveToMake == "U'") nav->aUp();
	else if (moveToMake == "U2") nav->up2();

	else if (moveToMake == "D") nav->down();
	else if (moveToMake == "D'") nav->aDown();
	else if (moveToMake == "D2") nav->down2();

	else if (moveToMake == "L") nav->left();
	else if (moveToMake == "L'") nav->aLeft();
	else if (moveToMake == "L2") nav->left2();

	else if (moveToMake == "R") nav->right();
	else if (moveToMake == "R'") nav->aRight();
	else if (moveToMake == "R2") nav->right2();

	else if (moveToMake == "F") nav->front();
	else if (moveToMake == "F'") nav->aFront();
	else if (moveToMake == "F2") nav->front2();

	else if (moveToMake == "B") nav->back();
	else if (moveToMake == "B'") nav->aBack();
	else if (moveToMake == "B2") nav->back2();

	else if (moveToMake == "x") nav->moveX();
	else if (moveToMake == "x'") nav->moveAx();
	else if (moveToMake == "x2") nav->moveX2();

	else if (moveToMake == "y") nav->moveY();
	else if (moveToMake == "y'") nav->moveAy();
	else if (moveToMake == "y2") nav->moveY2();

	else makeMove = false;

	return makeMove;
}

void makeCross(KubeNavigator *nav, KubePrinter *printer)
{
	nav->left2();
	nav->right2();
	nav->front2();
	nav->back2();
	nav->up2();
	nav->down2();

	printer->printKube();
}

void testNotation(KubeNavigator *nav, KubePrinter *printer)
{

	// nav->front();
	// cout << endl << "Move F" << endl << endl;;
	// printer->printKube();

	// nav->aFront();
	// cout << endl << "Move F'" << endl << endl;;
	// printer->printKube();


	// nav->back();
	// cout << endl << "Move B" << endl << endl;;
	// printer->printKube();

	// nav->aBack();
	// cout << endl << "Move B'" << endl << endl;;
	// printer->printKube();



	// nav->up();
	// cout << endl << "Move U" << endl << endl;;
	// printer->printKube();

	// nav->aUp();
	// cout << endl << "Move U'" << endl << endl;;
	// printer->printKube();

	// nav->down();
	// cout << endl << "Move D" << endl << endl;;
	// printer->printKube();

	// nav->aDown();
	// cout << endl << "Move D'" << endl << endl;;
	// printer->printKube();

	// nav->left();
	// cout << endl << "Move L" << endl << endl;;
	// printer->printKube();

	// nav->aLeft();
	// cout << endl << "Move L'" << endl << endl;;
	// printer->printKube();

	// nav->right();
	// cout << endl << "Move R" << endl << endl;;
	// printer->printKube();

	// nav->aRight();
	// cout << endl << "Move R'" << endl << endl;;
	// printer->printKube();



	nav->moveX();
	cout << endl << "Move X" << endl << endl;;
	printer->printKube();

	nav->moveAx();
	cout << endl << "Move X'" << endl << endl;;
	printer->printKube();

	nav->moveY();
	cout << endl << "Move Y" << endl << endl;;
	printer->printKube();

	nav->moveAy();
	cout << endl << "Move Y'" << endl << endl;;
	printer->printKube();
}