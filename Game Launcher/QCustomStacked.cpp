#include "QCustomStacked.h"

QCustomStacked::QCustomStacked(QWidget* parent) : QStackedWidget(parent) {};

QCustomStacked::~QCustomStacked() {};

void QCustomStacked::setGamePage(int gameid) {
	auto* gamePage = this->widget(1);
	
	auto* gameText = gamePage->findChild<QLabel *>("gameInfoName");
	gameText->setText("Counter-Strike");

};