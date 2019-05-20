#pragma once
#ifndef PLAYBUTTON_H
#define PLAYBUTTON_H
#include <QtWidgets>

class PlayButton : public QPushButton {
	Q_OBJECT

public:
	explicit PlayButton(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~PlayButton();

signals:
	void gameStart();

protected:
	void mousePressEvent(QMouseEvent* event);
};

#endif