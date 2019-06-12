#include "GameLauncher.h"
#include "json/writer.h"
GameLauncher::GameLauncher(QWidget *parent)
	: QMainWindow(parent)
{
	LoadJson lj;
	ui.setupUi(this);

	// 여러 ClickableQLabel의 목표를 설정해줍니다.
	ui.libraryLauncherTitle->target = 2;
	ui.launcherLibraryTitle->target = 0;
	ui.goBack->target = 0;
	ui.goBack_2->target = 0;
	Json::Value userdata = lj.LoadUserData(); // 유저 데이터 파일을 로드합니다.
	SIDCpp sid("the-intersection"); // SIDCpp 객체를 생성합니다.
	Json::Value loginData = sid.login(userdata["sid"]["clientid"].asCString(), userdata["sid"]["sessid"].asCString()); // 자동 로그인을 시도합니다.
	if (loginData["error"])
	{
		ui.stackedWidget->setCurrentIndex(3); // 자동 로그인이 실패하면, 로그인 창으로 보냅니다.
	}
	else
	{		
		ui.stackedWidget->setCurrentIndex(0); // 자동 로그인이 성공하면, 게임 라이브러리 창으로 보냅니다.
		ui.stackedWidget->setUsername(loginData["nickname"].asString()); // QCustomStacked에 있는 지정된 라벨들에 닉네임을 넣어줍니다.
		ui.steamidEnter->setText(userdata["steamid64"].asCString()); // 스팀 연동 입력 창에 현재 데이터를 넣어줍니다.
	}

	ui.stackedWidget->init(ui.scrollAreaWidgetContents); // QStackedWidget을 설정합니다.
	ui.stackedWidget->loginInit(ui.idEnter, ui.pwEnter); // 로그인 폼을 준비합니다.
	ui.stackedWidget->loadGameLibrary(); // 게임 라이브러리를 로드하고, 라이브러리 페이지에 표시합니다.
}

void GameLauncher::buttonClicked(int gameid) {
	
}