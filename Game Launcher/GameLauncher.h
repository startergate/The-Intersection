#pragma once

#include <QtWidgets/QMainWindow>
#include "LoadJson.h"
#include "GeneratedFiles/ui_GameLauncher.h"

class GameLauncher : public QMainWindow
{
	Q_OBJECT

public:
	GameLauncher(QWidget *parent = Q_NULLPTR);
public slots:
	void buttonClicked(int game);
signals:
	void loggedIn();
private:
	Ui::GameLauncherClass ui;
};