#pragma once
#ifndef GAMEBUTTON_H
#define GAMEBUTTON_H
#include <QtWidgets>

class GameButton : public QPushButton {
	Q_OBJECT

public:
	explicit GameButton(QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
	~GameButton();

	int gameid;

	void setGameid(int gameid);

signals:
	void changeStackedWidgetIndex(int);
	void changeGameWidget(int);

protected:
	void mousePressEvent(QMouseEvent* event);
};

#endif