#pragma once

#ifndef QCUSTOMSTACKED_H
#define QCUSTOMSTACKED_H
#include <Game.h>
#include <FlowLayout.h>
#include <GameButton.h>
#include <LoadJson.h>
#include <QString>
#include <QList>
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
	void init(QWidget*);

public slots:
	void setGamePage(int gameid);
	void setGameLibrary();
	void startGame();

private:
	QWidget* target;
	FlowLayout* library;
	QList<GameButton *> buttons;
	QFont font;
	std::string buttonStyleSheet = "border: 1px solid grey;\nborder-radius: 10px;\nbackground-repeat: no-repeat;\nbackground-position: center; color: white; padding-top: 70px;";
};

#endif