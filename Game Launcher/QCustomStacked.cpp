#include "QCustomStacked.h"

QCustomStacked::QCustomStacked(QWidget* parent) : QStackedWidget(parent) {};

QCustomStacked::~QCustomStacked() {};

void QCustomStacked::setGamePage(int gameid) {
	std::string json;
	auto* gamePage = this->widget(1);
	std::ifstream jsondata("people.json", std::ifstream::binary);
	jsondata >> json;
	rapidjson::Document data;

	char* jsons;
	sprintf(jsons, "%s", json);
	data.Parse(jsons);
	auto* gameText = gamePage->findChild<QLabel *>("gameInfoName");
	gameText->setText(data["title"].GetString());

};