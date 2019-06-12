#include "QCustomStacked.h"

QCustomStacked::QCustomStacked(QWidget* parent) : QStackedWidget(parent), target(target) {
	// UI에 필요한 변수들을 정의합니다.
	font.setFamily(QString::fromUtf8("Noto Sans KR Light"));
	font.setPointSize(11);
	this->library = new FlowLayout;
	this->sid = new SIDCpp("the-intersection");
};

QCustomStacked::~QCustomStacked() {};

void QCustomStacked::login() { // 직접 로그인을 실행합니다.
	Json::StyledWriter writer;
	std::string clientid = sid->createClientID("the-intersection"); // 기기 고유 ID를 만듭니다.
	Json::Value userdata = sid->login(clientid, id_form->text().toStdString(), pw_form->text().toStdString()); // 로그인을 실행합니다.
	if (userdata["error"])
	{
		return this->loginError(); // 에러가 발생하면 팝업을 띄웁니다.
	}

	LoadJson* lj = new LoadJson;
	
	Json::Value userdataFile = lj->LoadUserData(); // 유저 정보를 로드합니다.

	// 불러온 파일에 로그인한 유저의 정보를 넣습니다.
	userdataFile["sid"]["clientid"] = clientid;
	userdataFile["sid"]["sessid"] = userdata["sessid"];
	userdataFile["sid"]["pid"] = userdata["pid"];
	userdataFile["sid"]["nickname"] = userdata["nickname"];
	lj->Save("data/user.json", userdataFile); // 수정된 파일을 저장합니다.
	Json::Value game = lj->LoadLibraryOn(userdata["pid"].asString()); // 서버에 저장된 게임 라이브러리를 불러옵니다.
	lj->Save("data/game.json", game); // 로컬 게임 라이브러리 파일에 저장합니다.

	this->widget(4)->findChild<QLineEdit *>("steamidEnter")->setText(userdataFile["steamid64"].asCString()); // 유저가 로그아웃했다가 다시 로그인했을 경우를 대비해 연동된 스팀 계정을 리셋합니다.

	this->loadGameLibrary(); // 게임 라이브러리 창을 준비합니다.
	this->setCurrentIndex(0); // 게임 라이브러리 창을 표시합니다.
}

void QCustomStacked::loginError() {
	QMessageBox::information(0, QString("Error"), QString("Login failed. Try again."), QMessageBox::Ok); // 로그인 실패 메시지를 발신합니다.
}

void QCustomStacked::setGamePage(int gameid) {
	delete game;
	LoadJson* lj = new LoadJson;
	auto* gamePage = this->widget(1);
	Json::Value data = lj->LoadLibraryW(); // 게임 라이브러리를 로드합니다.
	char str[10];
	auto* gameText = gamePage->findChild<QLabel *>("gameInfoName");
	gameText->setText(data["games"][itoa(gameid, str, 10)]["name"].asCString()); // 게임 이름을 넣습니다.

	// 게임 플랫폼에 따라 객체를 생성합니다.
	if (data["games"][itoa(gameid, str, 10)]["platform"].asString().compare("steam") == 0)
	{
		game = new SteamGame(gameid, data["games"][itoa(gameid, str, 10)]["additional"]["steamid"].asInt());
	}
	else
	{
		game = new Game(gameid);
	}
};

void QCustomStacked::setUsername(std::string name) { // 게임 라이브러리 창과 게임 런처 목록 창에 있는 유저 닉네임을 설정합니다.
	std::string out = "Logged in as ";
	out += name;
	this->widget(0)->findChild<QLabel *>("libraryName")->setText(out.c_str());
	this->widget(2)->findChild<QLabel *>("launcherName")->setText(out.c_str());
}

void QCustomStacked::startGame() { // 게임을 시작합니다.
	this->game->execute();
}

void QCustomStacked::setGameLibrary() { // loadGameLibrary()를 실행하는 슬롯입니다.
	this->loadGameLibrary();
}

void QCustomStacked::loadGameLibrary() { // 게임 라이브러리를 로드하고 표시합니다.
	LoadJson lj;
	QList<GameButton*> buttons = library->findChildren<GameButton*>();
	for (size_t i = 0; i < buttons.length(); i++) // 현재 창에 있는 모든 게임 버튼을 지웁니다.
	{
		library->removeWidget(buttons[i]);
	}

	game->GameListGenerate(); // 게임 리스트를 다시 만듭니다.

	Json::Value data = lj.LoadLibrary(); // 게임 라이브러리를 로드합니다.
	Json::Value& games = data["games"];
	for (Json::ValueIterator it = games.begin(); it != games.end(); it++) {
		// 버튼들을 만듭니다.
		GameButton* button = new GameButton(target);
		std::string objectname = "game";
		objectname += (*it)["tiid"].asCString();
		button->setObjectName(QString::fromUtf8(objectname.c_str()));
		button->setGeometry(QRect(0, 0, 171, 101));
		button->setFont(font);
		std::string tempButtonStyleSheet = buttonStyleSheet;
		tempButtonStyleSheet += "background-image: url(\"GameThumbnail/";
		tempButtonStyleSheet.append((*it)["tiid"].asCString());
		tempButtonStyleSheet.append(".jpg\");\n");
		button->setStyleSheet(QString::fromUtf8(tempButtonStyleSheet.c_str()));
#ifndef QT_NO_ACCESSIBILITY
		button->setAccessibleName(QApplication::translate("GameLauncherClass", (*it)["name"].asCString(), nullptr));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
		button->setAccessibleDescription(QApplication::translate("GameLauncherClass", (*it)["tiid"].asCString(), nullptr));
#endif // QT_NO_ACCESSIBILITY
		button->setText(QApplication::translate("GameLauncherClass", (*it)["name"].asCString(), nullptr));
		button->setGameid((*it)["tiid"].asCString());
		QObject::connect(button, SIGNAL(changeStackedWidgetIndex(int)), this, SLOT(setCurrentIndex(int)));
		QObject::connect(button, SIGNAL(changeGameWidget(int)), this, SLOT(setGamePage(int)));
		buttons.append(button); // 버튼을 버튼 리스트에 추가합니다.
		library->addWidget(button);
	}
}

void QCustomStacked::init(QWidget* target) {
	// 주요 변수들을 초기화합니다.
	this->target = target;
	this->library->setParent(target);
	this->target->setLayout(library);
}

void QCustomStacked::loginInit(QLineEdit* id, QLineEdit* pw) {
	// 로그인 관련 폼을 가져옵니다.
	this->id_form = id;
	this->pw_form = pw;
}

void QCustomStacked::changeToUserTab() {
	// 유저 정보 탭으로 바꿉니다.
	this->setCurrentIndex(4);
}

void QCustomStacked::setSteamID64() { // 스팀 연동 계정을 바꿉니다.
	LoadJson* lj = new LoadJson;
	Json::Value userdata = lj->LoadUserData(); // 유저 데이터를 로드합니다.
	userdata["steamid64"] = this->widget(4)->findChild<QLineEdit *>("steamidEnter")->text().toStdString();
	lj->Save("data/user.json", userdata); // SteamID64를 다시 로드해 파일에 넣습니다.
	this->loadGameLibrary(); // 게임 라이브러리를 다시 로드합니다.
}

void QCustomStacked::logout() {
	LoadJson* lj = new LoadJson;
	Json::Value userdata = lj->LoadUserData(); // 유저 데이터를 로드합니다.
	this->sid->logout(userdata["sid"]["clientid"].asString(), userdata["sid"]["sessid"].asString()); // SID 서버와 통신해 로그아웃을 실행합니다.
	
	// 파일에 있는 유저 데이터를 지웁니다.
	userdata["sid"]["sessid"] = "";
	userdata["sid"]["nickname"] = "";
	userdata["sid"]["pid"] = "";
	lj->Save("data/user.json", userdata); // 유저 데이터를 지운 파일을 저장합니다.
	this->setCurrentIndex(3);
}