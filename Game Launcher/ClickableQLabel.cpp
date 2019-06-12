#include "ClickableQLabel.h"

ClickableLabel::ClickableLabel(QWidget* parent, Qt::WindowFlags f)
	: QLabel(parent) {

}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event) { // 마우스 클릭 이벤트를 감지합니다.
	emit changeStackedWidgetIndex(this->target); // changeStackedWidgetIndex(int) 시그널을 발생시킵니다.
}