#include "GameButton.h"

GameButton::GameButton(QWidget* parent, Qt::WindowFlags f, int gameid)
	: QPushButton(parent) {
	this->gameid = gameid;
}

GameButton::~GameButton() {}

void GameButton::mousePressEvent(QMouseEvent* event) {
	emit clicked(this->gameid);
}