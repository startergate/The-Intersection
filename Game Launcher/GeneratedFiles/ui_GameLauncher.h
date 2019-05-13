/********************************************************************************
** Form generated from reading UI file 'GameLauncher.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMELAUNCHER_H
#define UI_GAMELAUNCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtWidgets/QStyle>
#include <FlowLayout.h>
#include <list>

QT_BEGIN_NAMESPACE

class Ui_GameLauncherClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QWidget *widget;
	FlowLayout *AppLibrary;
    QPushButton *pushButton;

    void setupUi(QMainWindow *GameLauncherClass)
    {
        if (GameLauncherClass->objectName().isEmpty())
            GameLauncherClass->setObjectName(QString::fromUtf8("GameLauncherClass"));
        GameLauncherClass->setEnabled(true);
        GameLauncherClass->resize(1062, 788);
        centralWidget = new QWidget(GameLauncherClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 88)"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 116, 42));
        QFont font;
        font.setFamily(QString::fromUtf8("Avenir LT Std 65 Medium"));
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 80, 1001, 681));
		AppLibrary = new FlowLayout(10);
		AppLibrary->setSpacing(30);
		//AppLibrary->setMargin(10);
		//AppLibrary->setContentsMargins(11, 11, 11, 11);
		AppLibrary->setObjectName(QString::fromUtf8("Library"));
		//AppLibrary->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font1;
        font1.setKerning(true);
        pushButton->setFont(font1);
		pushButton->setStyleSheet(QString::fromUtf8("color: rgb(70, 70, 70);\n"
			"border-color: rgba(255, 255, 255, 0);\n"
			"background-color: rgb(70, 70, 70);\n"
			"width: 30px"));

		AppLibrary->addWidget(pushButton);

		/*std::list<QPushButton*> PushButtons;
		auto listbegin = PushButtons.begin();
		for (int i = 0; i < 15; i++)
		{
			QPushButton* btn = new QPushButton(widget);
			btn->setObjectName(QString::fromUtf8("pushButton"));
			QFont font1;
			font1.setKerning(true);
			btn->setFont(font1);
			btn->setStyleSheet(QString::fromUtf8("color: rgb(70, 70, 70);\n"
				"border-color: rgba(255, 255, 255, 0);\n"
				"background-color: rgb(70, 70, 70);\n"
				"width: 30px"
				"margin: 3px"));
			PushButtons.push_back(btn);
			AppLibrary->addWidget();
		}*/
        GameLauncherClass->setCentralWidget(centralWidget);

        retranslateUi(GameLauncherClass);

        QMetaObject::connectSlotsByName(GameLauncherClass);
    } // setupUi

    void retranslateUi(QMainWindow *GameLauncherClass)
    {
        GameLauncherClass->setWindowTitle(QApplication::translate("GameLauncherClass", "GameLauncher", nullptr));
        label->setText(QApplication::translate("GameLauncherClass", "Library", nullptr));
        pushButton->setText(QApplication::translate("GameLauncherClass", "\352\262\214\354\236\2041", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameLauncherClass: public Ui_GameLauncherClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMELAUNCHER_H
