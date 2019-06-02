#include "GameLauncher.h"

GameLauncher::GameLauncher(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.libraryLauncherTitle->target = 2;
	ui.launcherLibraryTitle->target = 0;
	ui.stackedWidget->setCurrentIndex(0);

	ui.stackedWidget->init(ui.scrollAreaWidgetContents);
	ui.stackedWidget->loadGameLibrary();
	//ui.stackedWidget->setCurrentIndex(3);
}

void GameLauncher::buttonClicked(int gameid) {
	
}