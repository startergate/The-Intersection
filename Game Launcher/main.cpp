#include "GameLauncher.h"
#include "Game.h"
#include <QtWidgets/QApplication>

Game* selectedGame = new Game();

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GameLauncher w;
	w.show();
	return a.exec();
}