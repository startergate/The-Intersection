#include "GameButton.h"

GameButton::GameButton(QWidget* parent, Qt::WindowFlags f)
	: QPushButton(parent) {

}

GameButton::~GameButton() {}

void GameButton::mousePressEvent(QMouseEvent* event) {
	emit clicked(this->gameid);
	
}

void GameButton::setGameid(int gameid) {
	this->gameid = gameid;
}