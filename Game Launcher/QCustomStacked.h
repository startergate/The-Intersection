#pragma once

#ifndef QCUSTOMSTACKED_H
#define QCUSTOMSTACKED_H
#include <Game.h>
#include <QWidget>
#include <QStackedWidget>
#include <QLabel>
#include <fstream>
#include "rapidjson/document.h"

class QCustomStacked : public QStackedWidget {
	Q_OBJECT

public:
	explicit QCustomStacked(QWidget* parent = Q_NULLPTR);
	~QCustomStacked();
	
	Game* game = new Game();

public slots:
	void setGamePage(int gameid);
};

#endif