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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameLauncherClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *libraryTab;
    QLabel *libraryLibraryTitle;
    QScrollArea *libraryApps;
    QWidget *scrollAreaWidgetContents;
    QPushButton *game10;
    QPushButton *game20;
    QLabel *libraryLauncherTitle;
    QWidget *gameInfoTab;
    QLabel *gameInfoName;
    QWidget *launcherTab;
    QLabel *launcherLibraryTitle;
    QLabel *launcherlauncherTitle;

    void setupUi(QMainWindow *GameLauncherClass)
    {
        if (GameLauncherClass->objectName().isEmpty())
            GameLauncherClass->setObjectName(QString::fromUtf8("GameLauncherClass"));
        GameLauncherClass->setEnabled(true);
        GameLauncherClass->resize(1024, 670);
        centralWidget = new QWidget(GameLauncherClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(88, 88, 88)"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        libraryTab = new QWidget();
        libraryTab->setObjectName(QString::fromUtf8("libraryTab"));
        libraryLibraryTitle = new QLabel(libraryTab);
        libraryLibraryTitle->setObjectName(QString::fromUtf8("libraryLibraryTitle"));
        libraryLibraryTitle->setGeometry(QRect(0, 10, 151, 62));
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
        libraryApps->setGeometry(QRect(0, 80, 1006, 323));
        libraryApps->setStyleSheet(QString::fromUtf8("border: 0;"));
        libraryApps->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1006, 323));
        game10 = new QPushButton(scrollAreaWidgetContents);
        game10->setObjectName(QString::fromUtf8("game10"));
        game10->setGeometry(QRect(10, 10, 169, 101));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Noto Sans KR Light"));
        font1.setPointSize(11);
        game10->setFont(font1);
        game10->setStyleSheet(QString::fromUtf8("border: 1px solid grey;\n"
"border-radius: 10px;\n"
"background-image: url(\"GameThumbnail/10.jpg\");\n"
"background-repeat: no-repeat;\n"
"background-position: center; color: white; padding-top: 70px;"));
        game20 = new QPushButton(scrollAreaWidgetContents);
        game20->setObjectName(QString::fromUtf8("game20"));
        game20->setGeometry(QRect(190, 10, 171, 101));
        game20->setFont(font1);
        game20->setStyleSheet(QString::fromUtf8("border: 1px solid grey;\n"
"border-radius: 10px;\n"
"background-image: url(\"GameThumbnail/570.jpg\");\n"
"background-repeat: no-repeat;\n"
"background-position: center; color: white; padding-top: 70px;"));
        libraryApps->setWidget(scrollAreaWidgetContents);
        libraryLauncherTitle = new QLabel(libraryTab);
        libraryLauncherTitle->setObjectName(QString::fromUtf8("libraryLauncherTitle"));
        libraryLauncherTitle->setGeometry(QRect(140, 10, 181, 62));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Avenir LT 35 Light"));
        font2.setPointSize(26);
        font2.setBold(false);
        font2.setWeight(50);
        libraryLauncherTitle->setFont(font2);
        libraryLauncherTitle->setStyleSheet(QString::fromUtf8("color: rgb(128, 128, 128);\n"
"margin: 10px;"));
        stackedWidget->addWidget(libraryTab);
        gameInfoTab = new QWidget();
        gameInfoTab->setObjectName(QString::fromUtf8("gameInfoTab"));
        gameInfoName = new QLabel(gameInfoTab);
        gameInfoName->setObjectName(QString::fromUtf8("gameInfoName"));
        gameInfoName->setGeometry(QRect(0, 10, 1006, 62));
        gameInfoName->setFont(font);
        gameInfoName->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"margin: 10px;"));
        stackedWidget->addWidget(gameInfoTab);
        launcherTab = new QWidget();
        launcherTab->setObjectName(QString::fromUtf8("launcherTab"));
        launcherLibraryTitle = new QLabel(launcherTab);
        launcherLibraryTitle->setObjectName(QString::fromUtf8("launcherLibraryTitle"));
        launcherLibraryTitle->setGeometry(QRect(0, 10, 151, 62));
        launcherLibraryTitle->setFont(font2);
        launcherLibraryTitle->setStyleSheet(QString::fromUtf8("color: rgb(128, 128, 128);\n"
"margin: 10px;"));
        launcherlauncherTitle = new QLabel(launcherTab);
        launcherlauncherTitle->setObjectName(QString::fromUtf8("launcherlauncherTitle"));
        launcherlauncherTitle->setGeometry(QRect(140, 10, 181, 62));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Avenir LT 65 Medium"));
        font3.setPointSize(26);
        font3.setBold(true);
        font3.setWeight(75);
        launcherlauncherTitle->setFont(font3);
        launcherlauncherTitle->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"margin: 10px;"));
        stackedWidget->addWidget(launcherTab);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        GameLauncherClass->setCentralWidget(centralWidget);

        retranslateUi(GameLauncherClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(GameLauncherClass);
    } // setupUi

    void retranslateUi(QMainWindow *GameLauncherClass)
    {
        GameLauncherClass->setWindowTitle(QApplication::translate("GameLauncherClass", "GameLauncher", nullptr));
        libraryLibraryTitle->setText(QApplication::translate("GameLauncherClass", "Library", nullptr));
#ifndef QT_NO_WHATSTHIS
        libraryApps->setWhatsThis(QApplication::translate("GameLauncherClass", "Counter-Strike", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        game10->setAccessibleName(QApplication::translate("GameLauncherClass", "Counter-Strike", nullptr));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        game10->setAccessibleDescription(QApplication::translate("GameLauncherClass", "10", nullptr));
#endif // QT_NO_ACCESSIBILITY
        game10->setText(QApplication::translate("GameLauncherClass", "Counter-Strike", nullptr));
#ifndef QT_NO_ACCESSIBILITY
        game20->setAccessibleName(QApplication::translate("GameLauncherClass", "Counter-Strike", nullptr));
#endif // QT_NO_ACCESSIBILITY
#ifndef QT_NO_ACCESSIBILITY
        game20->setAccessibleDescription(QApplication::translate("GameLauncherClass", "20", nullptr));
#endif // QT_NO_ACCESSIBILITY
        game20->setText(QApplication::translate("GameLauncherClass", "Dota 2", nullptr));
        libraryLauncherTitle->setText(QApplication::translate("GameLauncherClass", "Launcher", nullptr));
        gameInfoName->setText(QApplication::translate("GameLauncherClass", "GAME_NAME", nullptr));
        launcherLibraryTitle->setText(QApplication::translate("GameLauncherClass", "Library", nullptr));
        launcherlauncherTitle->setText(QApplication::translate("GameLauncherClass", "Launcher", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameLauncherClass: public Ui_GameLauncherClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMELAUNCHER_H
