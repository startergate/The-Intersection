#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_GameLauncher.h"

class GameLauncher : public QMainWindow
{
	Q_OBJECT

public:
	GameLauncher(QWidget *parent = Q_NULLPTR);

private:
	Ui::GameLauncherClass ui;
};
