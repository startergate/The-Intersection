#include "GameButton.h"
#include <string>

GameButton::GameButton(QWidget* parent, Qt::WindowFlags f)
	: QPushButton(parent) {

}

GameButton::~GameButton() {}

void GameButton::mousePressEvent(QMouseEvent* event) {
	OutputDebugString(L" 게임버튼 눌림 \n");
	setGameid(10);
	char id[3];
	//sprintf(id, "%d", this->gameid);
	//OutputDebugStringA(id);
	emit changeStackedWidgetIndex(1);
	emit changeGameWidget(this->gameid);
}

void GameButton::setGameid(int gameid) {
	this->gameid = gameid;
}