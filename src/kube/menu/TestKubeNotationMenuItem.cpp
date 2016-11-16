#include "TestKubeNotationMenuItem.h"
#include "../KubeLoader.h"
#include "../KubePrinter.h"
#include "../KubeColorMapper.h"
#include "../KubeNavigator.h"
#include "../KubeTracer.h"
#include "../../shared/InOut.h"


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

	KubeTracer *tracer = new KubeTracer;
	KubeNavigator *nav = new KubeNavigator(kube, tracer);
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

	logSrv->printl("Trace: " + tracer->convertToString());
	logSrv->printl("");
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

	if (moveToMake == KubeTracer::UP_STR) nav->up();
	else if (moveToMake == KubeTracer::ANTI_UP_STR) nav->aUp();
	else if (moveToMake == KubeTracer::DOUBLE_UP_STR) nav->up2();

	else if (moveToMake == KubeTracer::DOWN_STR) nav->down();
	else if (moveToMake == KubeTracer::ANTI_DOWN_STR) nav->aDown();
	else if (moveToMake == KubeTracer::DOUBLE_DOWN_STR) nav->down2();

	else if (moveToMake == KubeTracer::LEFT_STR) nav->left();
	else if (moveToMake == KubeTracer::ANTI_LEFT_STR) nav->aLeft();
	else if (moveToMake == KubeTracer::DOUBLE_LEFT_STR) nav->left2();

	else if (moveToMake == KubeTracer::RIGHT_STR) nav->right();
	else if (moveToMake == KubeTracer::ANTI_RIGHT_STR) nav->aRight();
	else if (moveToMake == KubeTracer::DOUBLE_RIGHT_STR) nav->right2();

	else if (moveToMake == KubeTracer::FRONT_STR) nav->front();
	else if (moveToMake == KubeTracer::ANTI_FRONT_STR) nav->aFront();
	else if (moveToMake == KubeTracer::DOUBLE_FRONT_STR) nav->front2();

	else if (moveToMake == KubeTracer::BACK_STR) nav->back();
	else if (moveToMake == KubeTracer::ANTI_BACK_STR) nav->aBack();
	else if (moveToMake == KubeTracer::DOUBLE_BACK_STR) nav->back2();

	else if (moveToMake == KubeTracer::X_STR) nav->moveX();
	else if (moveToMake == KubeTracer::ANTI_X_STR) nav->moveAx();
	else if (moveToMake == KubeTracer::DOUBLE_X_STR) nav->moveX2();

	else if (moveToMake == KubeTracer::Y_STR) nav->moveY();
	else if (moveToMake == KubeTracer::ANTI_Y_STR) nav->moveAy();
	else if (moveToMake == KubeTracer::DOUBLE_Y_STR) nav->moveY2();

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