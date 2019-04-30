#include "GameLauncher.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GameLauncher w;
	w.setFixedSize(1062, 788);
	w.show();
	return a.exec();
}
