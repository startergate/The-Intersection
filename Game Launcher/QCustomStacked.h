#pragma once

#ifndef QCUSTOMSTACKED_H
#define QCUSTOMSTACKED_H
#include <Game.h>
#include <FlowLayout.h>
#include <QtWidgets>
#include <QStackedWidget>
#include <QLabel>
#include <fstream>
#include <rapidjson/document.h>
#include <rapidjson/istreamwrapper.h>
#include <sstream>
#include <string>


class QCustomStacked : public QStackedWidget {
	Q_OBJECT

public:
	explicit QCustomStacked(QWidget* parent = Q_NULLPTR);
	~QCustomStacked();
	
	Game* game = new SteamGame(10, 10);

	void loadGameLibrary();

public slots:
	void setGamePage(int gameid);
	void setGameLibrary();
	void startGame();

private:
	FlowLayout* library;
};

#endif