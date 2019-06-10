#include "GameLauncher.h"
#include "json/writer.h"
GameLauncher::GameLauncher(QWidget *parent)
	: QMainWindow(parent)
{
	LoadJson lj;
	ui.setupUi(this);

	ui.libraryLauncherTitle->target = 2;
	ui.launcherLibraryTitle->target = 0;
	ui.goBack->target = 0;
	ui.goBack_2->target = 0;
	Json::Value userdata = lj.LoadUserData();
	SIDCpp sid("the-intersection");
	Json::Value loginData = sid.login(userdata["sid"]["clientid"].asCString(), userdata["sid"]["sessid"].asCString());
	if (loginData["error"])
	{
		ui.stackedWidget->setCurrentIndex(3);
	}
	else
	{
		ui.stackedWidget->setCurrentIndex(0);
		ui.stackedWidget->setUsername(loginData["nickname"].asString());
		ui.steamidEnter->setText(userdata["steamid64"].asCString());
	}

	ui.stackedWidget->init(ui.scrollAreaWidgetContents);
	ui.stackedWidget->loginInit(ui.idEnter, ui.pwEnter);
	ui.stackedWidget->loadGameLibrary();
}

void GameLauncher::buttonClicked(int gameid) {
	
}