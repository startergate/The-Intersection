#include "QCustomStacked.h"

QCustomStacked::QCustomStacked(QWidget* parent) : QStackedWidget(parent) {};

QCustomStacked::~QCustomStacked() {};

void QCustomStacked::setGamePage(int gameid) {
	std::string json;
	//delete game;
	auto* gamePage = this->widget(1);
	std::ifstream jsondata("people.json");
	OutputDebugString(L" We are fine 1 \n");

	rapidjson::IStreamWrapper jsons(jsondata);
	rapidjson::Document data;
	OutputDebugString(L" We are fine 2 \n");

	data.ParseStream(jsons);
	game = new SteamGame(gameid, data["additional"]["steamid"].GetInt());
	auto* gameText = gamePage->findChild<QLabel *>("gameInfoName");
	gameText->setText(data["title"].GetString());

};

void QCustomStacked::startGame() {
	this->game->execute();
}