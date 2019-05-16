#include "GameLauncher.h"

GameLauncher::GameLauncher(QWidget *parent)
	: QMainWindow(parent)
{

	//connect(ui.pushButton, SIGNAL(clicked(int)), this, SLOT(buttonClicked(int)));
	ui.setupUi(this);
	
}

void GameLauncher::buttonClicked(int gameid) {
	
}