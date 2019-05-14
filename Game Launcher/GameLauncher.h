#pragma once

#include <QtWidgets/QMainWindow>
#include "GeneratedFiles/ui_GameLauncher.h"

class GameLauncher : public QMainWindow
{
	Q_OBJECT

public:
	GameLauncher(QWidget *parent = Q_NULLPTR);
public slots:
	void buttonClicked(int game);
private:
	Ui::GameLauncherClass ui;
};

void GameLauncher::buttonClicked(int game) {

}