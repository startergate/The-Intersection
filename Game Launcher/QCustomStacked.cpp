#include "QCustomStacked.h"

QCustomStacked::QCustomStacked(QWidget* parent) : QStackedWidget(parent), target(target) {
	font.setFamily(QString::fromUtf8("Noto Sans KR Light"));
	font.setPointSize(11);
	this->library = new FlowLayout;
};

QCustomStacked::~QCustomStacked() {};


void QCustomStacked::setGamePage(int gameid) {
	delete game;
	auto* gamePage = this->widget(1);
	LoadJson* lj = new LoadJson;
	rapidjson::Document data = lj->LoadLibraryW();
	char str[10];
	auto* gameText = gamePage->findChild<QLabel *>("gameInfoName");
	gameText->setText(data["games"][itoa(gameid, str, 10)]["name"].GetString());
	game = new SteamGame(gameid, data["games"][itoa(gameid, str, 10)]["additional"]["steamid"].GetInt());

};

void QCustomStacked::startGame() {
	this->game->execute();
}

void QCustomStacked::setGameLibrary() {
	this->loadGameLibrary();
}

void QCustomStacked::loadGameLibrary() {
	LoadJson lj;
	QList<GameButton*> buttons = library->findChildren<GameButton*>();
	for (size_t i = 0; i < buttons.length(); i++)
	{
		library->removeWidget(buttons[i]);
	}

	game->GameListGenerate();

	rapidjson::Document data = lj.LoadLibrary();
	rapidjson::Value& games = data["games"];
	for (rapidjson::Value::ConstMemberIterator it = games.MemberBegin(); it != games.MemberEnd(); it++) {
		GameButton* button = new GameButton(target);
		std::string objectname = "game";
		objectname += it->value["tiid"].GetString();
		button->setObjectName(QString::fromUtf8(objectname.c_str()));
		button->setGeometry(QRect(0, 0, 171, 101));
		button->setFont(font);
		std::string tempButtonStyleSheet = buttonStyleSheet;
		tempButtonStyleSheet += "background-image: url(\"GameThumbnail/";
		tempButtonStyleSheet.append(it->value["tiid"].GetString());
		tempButtonStyleSheet.append(".jpg\");\n");
		button->setStyleSheet(QString::fromUtf8(tempButtonStyleSheet.c_str()));
#ifndef QT_NO_ACCESSIBILITY
		button->setAccessibleName(QApplication::translate("GameLauncherClass", it->value["name"].GetString(), nullptr));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
		button->setAccessibleDescription(QApplication::translate("GameLauncherClass", it->value["tiid"].GetString(), nullptr));
#endif // QT_NO_ACCESSIBILITY
		button->setText(QApplication::translate("GameLauncherClass", it->value["name"].GetString(), nullptr));
		button->setGameid(it->value["tiid"].GetString());
		QObject::connect(button, SIGNAL(changeStackedWidgetIndex(int)), this, SLOT(setCurrentIndex(int)));
		QObject::connect(button, SIGNAL(changeGameWidget(int)), this, SLOT(setGamePage(int)));
		buttons.append(button);
		library->addWidget(button);
	}
}

void QCustomStacked::init(QWidget* target) {
	this->target = target;
	this->library->setParent(target);
	this->target->setLayout(library);
}