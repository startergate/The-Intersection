#include "PlayButton.h"

PlayButton::PlayButton(QWidget* parent, Qt::WindowFlags f) : QPushButton(parent) {}
PlayButton::~PlayButton() {}

void PlayButton::mousePressEvent(QMouseEvent* event) {
	emit gameStart();
}