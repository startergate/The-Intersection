#include "GameLauncher.h"

GameLauncher::GameLauncher(QWidget *parent)
	: QMainWindow(parent)
{
	ui.libraryLauncherTitle->target = 2;
	ui.launcherLibraryTitle->target = 0;
	ui.stackedWidget->setCurrentIndex(3);
	//connect(ui.pushButton, SIGNAL(clicked(int)), this, SLOT(buttonClicked(int)));
	ui.setupUi(this);
	
}

void GameLauncher::buttonClicked(int gameid) {
	
}