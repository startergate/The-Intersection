#include "QCustomStacked.h"
#include <typeinfo>

QCustomStacked::QCustomStacked(QWidget* parent) : QStackedWidget(parent) {};

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
	library = new FlowLayout;
	//library->addItem();
}