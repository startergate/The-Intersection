/********************************************************************************
** Form generated from reading UI file 'GameLauncher.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMELAUNCHER_H
#define UI_GAMELAUNCHER_H

#include <ClickableQLabel.h>
#include <PlayButton.h>
#include <QCustomStacked.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameLauncherClass
{
public:
    QWidget *centralWidget;
    QCustomStacked *stackedWidget;
    QWidget *libraryTab;
    QLabel *libraryLibraryTitle;
    QScrollArea *libraryApps;
    QWidget *scrollAreaWidgetContents;
    ClickableLabel *libraryLauncherTitle;
    QWidget *gameInfoTab;
    QLabel *gameInfoName;
    PlayButton *gameStartButton;
    ClickableLabel *goBack;
    QWidget *launcherTab;
    ClickableLabel *launcherLibraryTitle;
    QLabel *launcherlauncherTitle;
    QWidget *loginTab;
    QFrame *frame;
    QPushButton *loginBtn;
    QLineEdit *pwEnter;
    QLabel *pwDesc;
    QLabel *idDesc;
    QLineEdit *idEnter;
    QLabel *loginText;

    void setupUi(QMainWindow *GameLauncherClass)
    {
        if (GameLauncherClass->objectName().isEmpty())
            GameLauncherClass->setObjectName(QString::fromUtf8("GameLauncherClass"));
        GameLauncherClass->setEnabled(true);
        GameLauncherClass->resize(1035, 810);
        centralWidget = new QWidget(GameLauncherClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 88)"));
        stackedWidget = new QCustomStacked(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(9, 9, 1017, 792));
        libraryTab = new QWidget();
        libraryTab->setObjectName(QString::fromUtf8("libraryTab"));
        libraryLibraryTitle = new QLabel(libraryTab);
        libraryLibraryTitle->setObjectName(QString::fromUtf8("libraryLibraryTitle"));
        libraryLibraryTitle->setGeometry(QRect(0, 0, 151, 62));
        QFont font;
        font.setFamily(QString::fromUtf8("Avenir LT Std 65 Medium"));
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        libraryLibraryTitle->setFont(font);
        libraryLibraryTitle->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"margin: 10px;"));
        libraryApps = new QScrollArea(libraryTab);
        libraryApps->setObjectName(QString::fromUtf8("libraryApps"));
        libraryApps->setGeometry(QRect(0, 80, 1006, 711));
        libraryApps->setStyleSheet(QString::fromUtf8("border: 0;"));
        libraryApps->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1006, 711));
        libraryApps->setWidget(scrollAreaWidgetContents);
        libraryLauncherTitle = new ClickableLabel(libraryTab);
        libraryLauncherTitle->setObjectName(QString::fromUtf8("libraryLauncherTitle"));
        libraryLauncherTitle->setGeometry(QRect(140, 0, 181, 62));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Avenir LT 35 Light"));
        font1.setPointSize(26);
        font1.setBold(false);
        font1.setWeight(50);
        libraryLauncherTitle->setFont(font1);
        libraryLauncherTitle->setStyleSheet(QString::fromUtf8("color: rgb(128, 128, 128);\n"
"margin: 10px;"));
        stackedWidget->addWidget(libraryTab);
        gameInfoTab = new QWidget();
        gameInfoTab->setObjectName(QString::fromUtf8("gameInfoTab"));
        gameInfoName = new QLabel(gameInfoTab);
        gameInfoName->setObjectName(QString::fromUtf8("gameInfoName"));
        gameInfoName->setGeometry(QRect(65, 0, 941, 62));
        gameInfoName->setFont(font);
        gameInfoName->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"margin: 10px;"));
        gameStartButton = new PlayButton(gameInfoTab);
        gameStartButton->setObjectName(QString::fromUtf8("gameStartButton"));
        gameStartButton->setGeometry(QRect(20, 70, 91, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Avenir LT 55 Roman"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        gameStartButton->setFont(font2);
        goBack = new ClickableLabel(gameInfoTab);
        goBack->setObjectName(QString::fromUtf8("goBack"));
        goBack->setGeometry(QRect(-10, -10, 91, 81));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Avenir LT Std 65 Medium"));
        font3.setPointSize(50);
        font3.setBold(true);
        font3.setWeight(75);
        goBack->setFont(font3);
        goBack->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"margin: 10px;"));
        stackedWidget->addWidget(gameInfoTab);
        launcherTab = new QWidget();
        launcherTab->setObjectName(QString::fromUtf8("launcherTab"));
        launcherLibraryTitle = new ClickableLabel(launcherTab);
        launcherLibraryTitle->setObjectName(QString::fromUtf8("launcherLibraryTitle"));
        launcherLibraryTitle->setGeometry(QRect(0, 0, 151, 62));
        launcherLibraryTitle->setFont(font1);
        launcherLibraryTitle->setStyleSheet(QString::fromUtf8("color: rgb(128, 128, 128);\n"
"margin: 10px;"));
        launcherlauncherTitle = new QLabel(launcherTab);
        launcherlauncherTitle->setObjectName(QString::fromUtf8("launcherlauncherTitle"));
        launcherlauncherTitle->setGeometry(QRect(140, 0, 181, 62));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Avenir LT 65 Medium"));
        font4.setPointSize(26);
        font4.setBold(true);
        font4.setWeight(75);
        launcherlauncherTitle->setFont(font4);
        launcherlauncherTitle->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"margin: 10px;"));
        stackedWidget->addWidget(launcherTab);
        loginTab = new QWidget();
        loginTab->setObjectName(QString::fromUtf8("loginTab"));
        loginTab->setLayoutDirection(Qt::LeftToRight);
        loginTab->setStyleSheet(QString::fromUtf8(""));
        frame = new QFrame(loginTab);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(330, 260, 351, 251));
        loginBtn = new QPushButton(frame);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
        loginBtn->setGeometry(QRect(120, 170, 121, 51));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Avenir LT 45 Book"));
        font5.setPointSize(15);
        loginBtn->setFont(font5);
        loginBtn->setStyleSheet(QString::fromUtf8("background-color: white;border: 1px solid grey;border-radius: 10px"));
        pwEnter = new QLineEdit(frame);
        pwEnter->setObjectName(QString::fromUtf8("pwEnter"));
        pwEnter->setGeometry(QRect(110, 120, 170, 30));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Aleo"));
        font6.setPointSize(15);
        pwEnter->setFont(font6);
        pwEnter->setStyleSheet(QString::fromUtf8("background-color: white;color:black;"));
        pwDesc = new QLabel(frame);
        pwDesc->setObjectName(QString::fromUtf8("pwDesc"));
        pwDesc->setGeometry(QRect(70, 120, 30, 24));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Avenir LT 35 Light"));
        font7.setPointSize(15);
        pwDesc->setFont(font7);
        pwDesc->setStyleSheet(QString::fromUtf8("color:white"));
        pwDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        idDesc = new QLabel(frame);
        idDesc->setObjectName(QString::fromUtf8("idDesc"));
        idDesc->setGeometry(QRect(80, 90, 20, 24));
        idDesc->setFont(font7);
        idDesc->setStyleSheet(QString::fromUtf8("color:white"));
        idDesc->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        idEnter = new QLineEdit(frame);
        idEnter->setObjectName(QString::fromUtf8("idEnter"));
        idEnter->setGeometry(QRect(110, 90, 170, 30));
        idEnter->setFont(font6);
        idEnter->setStyleSheet(QString::fromUtf8("background-color: white;color:black;"));
        loginText = new QLabel(frame);
        loginText->setObjectName(QString::fromUtf8("loginText"));
        loginText->setGeometry(QRect(120, 10, 112, 52));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Avenir LT Std 65 Medium"));
        font8.setPointSize(32);
        loginText->setFont(font8);
        loginText->setStyleSheet(QString::fromUtf8("color: white"));
        loginText->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(loginTab);
        GameLauncherClass->setCentralWidget(centralWidget);

        retranslateUi(GameLauncherClass);
        QObject::connect(libraryLauncherTitle, SIGNAL(changeStackedWidgetIndex(int)), stackedWidget, SLOT(setCurrentIndex(int)));
        QObject::connect(launcherLibraryTitle, SIGNAL(changeStackedWidgetIndex(int)), stackedWidget, SLOT(setCurrentIndex(int)));
        QObject::connect(gameStartButton, SIGNAL(gameStart()), stackedWidget, SLOT(startGame()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GameLauncherClass);
    } // setupUi

    void retranslateUi(QMainWindow *GameLauncherClass)
    {
        GameLauncherClass->setWindowTitle(QApplication::translate("GameLauncherClass", "The Intersection", nullptr));
        libraryLibraryTitle->setText(QApplication::translate("GameLauncherClass", "Library", nullptr));
#ifndef QT_NO_WHATSTHIS
        libraryApps->setWhatsThis(QApplication::translate("GameLauncherClass", "Counter-Strike", nullptr));
#endif // QT_NO_WHATSTHIS
        libraryLauncherTitle->setText(QApplication::translate("GameLauncherClass", "Launcher", nullptr));
        gameInfoName->setText(QApplication::translate("GameLauncherClass", "GAME_NAME", nullptr));
        gameStartButton->setText(QApplication::translate("GameLauncherClass", "\342\226\266 Play", nullptr));
        goBack->setText(QApplication::translate("GameLauncherClass", "<", nullptr));
        launcherLibraryTitle->setText(QApplication::translate("GameLauncherClass", "Library", nullptr));
        launcherlauncherTitle->setText(QApplication::translate("GameLauncherClass", "Launcher", nullptr));
        loginBtn->setText(QApplication::translate("GameLauncherClass", "Login", nullptr));
        pwEnter->setInputMask(QString());
        pwEnter->setText(QApplication::translate("GameLauncherClass", "\354\213\234\353\260\234\354\236\220\354\202\264", nullptr));
        pwDesc->setText(QApplication::translate("GameLauncherClass", "PW", nullptr));
        idDesc->setText(QApplication::translate("GameLauncherClass", "ID", nullptr));
        idEnter->setInputMask(QString());
        idEnter->setText(QApplication::translate("GameLauncherClass", "\354\213\234\353\260\234\354\236\220\354\202\264", nullptr));
        loginText->setText(QApplication::translate("GameLauncherClass", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameLauncherClass: public Ui_GameLauncherClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMELAUNCHER_H
