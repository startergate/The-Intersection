#include "QCustomStacked.h"

QCustomStacked::QCustomStacked(QWidget* parent) : QStackedWidget(parent) {
	font.setFamily(QString::fromUtf8("Noto Sans KR Light"));
	font.setPointSize(11);
	library = new FlowLayout;
	library->setParent(target);
	target->setLayout(library);
};

QCustomStacked::~QCustomStacked() {};


void QCustomStacked::setGamePage(int gameid) {
	delete game;
	auto* gamePage = this->widget(1);
	rapidjson::Document data = LoadJson::LoadLibrary();
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
	QList<GameButton*> buttons = library->findChildren<GameButton*>();
	for (size_t i = 0; i < buttons.length(); i++)
	{
		library->removeWidget(buttons[i]);
	}

	game->GameListGenerate();

	rapidjson::Document data = LoadJson::LoadLibrary();
	rapidjson::Value& games = data["games"];
	for (rapidjson::Value::ConstMemberIterator it = games.MemberBegin(); it != games.MemberEnd(); it++) {
		it->value["template"].GetString();

		GameButton* button = new GameButton(target);
		std::string objectname = "game";
		objectname += it->value["tiid"].GetString();
		button->setObjectName(QString::fromUtf8(objectname.c_str()));
		button->setGeometry(QRect(190, 10, 171, 101));
		button->setFont(font);
		QString tempButtonStyleSheet = buttonStyleSheet;
		std::string background = "background-image: url(\"GameThumbnail/";
		background.append(it->value["tiid"].GetString());
		background.append(".jpg\");\n");
		tempButtonStyleSheet.append("background-image: url(\"GameThumbnail/570.jpg\");\n");
		button->setStyleSheet(tempButtonStyleSheet);
		buttons.append(button);
	}
}