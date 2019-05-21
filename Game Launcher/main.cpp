#include "GameLauncher.h"
#include "Game.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GameLauncher w;
	w.show();
	return a.exec();
}