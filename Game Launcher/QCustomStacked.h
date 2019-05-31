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
	QWidget* target;
	void loadGameLibrary();

public slots:
	void setGamePage(int gameid);
	void setGameLibrary();
	void startGame();

private:
	FlowLayout* library;
	QList<GameButton *> buttons;
	QFont font;
	QString buttonStyleSheet = QString::fromUtf8("border: 1px solid grey;\n"
		"border-radius: 10px;\n"
		//"background-image: url(\"GameThumbnail/10.jpg\");\n"
		"background-repeat: no-repeat;\n"
		"background-position: center; color: white; padding-top: 70px;");
};

#endif