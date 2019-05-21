#pragma once

#ifndef QCUSTOMSTACKED_H
#define QCUSTOMSTACKED_H
#include <Game.h>
#include <QtWidgets>
#include <QStackedWidget>
#include <QLabel>
#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>

class QCustomStacked : public QStackedWidget {
	Q_OBJECT

public:
	explicit QCustomStacked(QWidget* parent = Q_NULLPTR);
	~QCustomStacked();
	
	SteamGame* game = new SteamGame(10, 10);

public slots:
	void setGamePage(int gameid);
	void startGame();
};

#endif