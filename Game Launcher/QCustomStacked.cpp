#include "QCustomStacked.h"

void QCustomStacked::setGamePage(int gameid) {
	auto* gamePage = this->widget(1);
	gamePage->findChild<QLabel>("gameInfoName").setText()
}