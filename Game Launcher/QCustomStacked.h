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
#include <QMessageBox>
#include <fstream>
#include <sstream>
#include <string>
#include "json/json.h"
#include "sid.h"

class QCustomStacked : public QStackedWidget {
	Q_OBJECT

public:
	explicit QCustomStacked(QWidget* parent = Q_NULLPTR);
	~QCustomStacked();
	
	Game* game = new SteamGame(10, 10);
	SIDCpp* sid;
	void loadGameLibrary();
	void init(QWidget*);
	void loginInit(QLineEdit*, QLineEdit*);
	void loginError();
	void setUsername(std::string);

public slots:
	void setGamePage(int gameid);
	void setGameLibrary();
	void startGame();
	void login();

private:
	QWidget* target;
	FlowLayout* library;
	QList<GameButton *> buttons;
	QLabel* libraryName;
	QLabel* launcherName;
	QFont font;
	std::string buttonStyleSheet = "border: 1px solid grey;\nborder-radius: 10px;\nbackground-repeat: no-repeat;\nbackground-position: center; color: white; padding-top: 70px;";

	QLineEdit* id_form;
	QLineEdit* pw_form;
};

#endif