#include "GameButton.h"

GameButton::GameButton(QWidget* parent, Qt::WindowFlags f)
	: QPushButton(parent) {

}

GameButton::~GameButton() {}

void GameButton::mousePressEvent(QMouseEvent* event) { // 마우스 클릭을 감지합니다.
	char id[3];
	//sprintf(id, "%d", this->gameid);
	//OutputDebugStringA(id);
	emit changeStackedWidgetIndex(1); // changeStackedWidgetIndex(int) 시그널을 발생시킵니다.
	emit changeGameWidget(this->gameid); // changeGameWidget(int) 시그널을 발생시켜 게임 정보 창에 게임 정보를 표시합니다.
}

void GameButton::setGameid(int gameid) {
	this->gameid = gameid; // gameid를 숫자로 가져옵니다.
}

void GameButton::setGameid(std::string gameid) {
	this->gameid = atoi(gameid.c_str()); // gameid를 string으로 가져와 int로 변환합니다.
}