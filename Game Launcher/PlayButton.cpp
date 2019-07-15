#include "PlayButton.h"

PlayButton::PlayButton(QWidget* parent, Qt::WindowFlags f) : QPushButton(parent) {}
PlayButton::~PlayButton() {}

void PlayButton::mousePressEvent(QMouseEvent* event) { // 마우스 클릭 이벤트를 감지합니다.
    emit gameStart(); // gameStart(void) 시그널을 발생시켜 게임을 시작합니다.
}