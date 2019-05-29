#include "QCustomStacked.h"

QCustomStacked::QCustomStacked(QWidget* parent) : QStackedWidget(parent) {
	font.setFamily(QString::fromUtf8("Noto Sans KR Light"));
	font.setPointSize(11);
	library = new FlowLayout;
	library->setParent(target);
};

QCustomStacked::~QCustomStacked() {};

void QCustomStacked::setGamePage(int gameid) {
	std::string json;
	//delete game;
	auto* gamePage = this->widget(1);
	std::ifstream jsondata("data/game.json");

	rapidjson::IStreamWrapper jsons(jsondata);
	rapidjson::Document data;

	data.ParseStream(jsons);
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
	

	//library->addItem();
}