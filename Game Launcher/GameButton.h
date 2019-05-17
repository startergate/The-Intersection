#pragma once
#ifndef GAMEBUTTON_H
#define GAMEBUTTON_H
#include <QtWidgets>

class GameButton : public QPushButton {
	Q_OBJECT

public:
	explicit GameButton(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags(), int gameid = 10);
	~GameButton();

	int gameid;

signals:
	void clicked(int);

protected:
	void mousePressEvent(QMouseEvent* event);
};

#endif