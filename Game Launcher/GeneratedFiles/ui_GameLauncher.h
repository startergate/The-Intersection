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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameLauncherClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton;
    QLabel *label;

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
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setStyleSheet(QString::fromUtf8("border: 0;"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1006, 584));
        pushButton = new QPushButton(scrollAreaWidgetContents);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(7, 7, 50, 50));
        pushButton->setStyleSheet(QString::fromUtf8("border: 1px solid grey;\n"
"border-radius: 10px;\n"
"background-image: url(\"GameThumbnail/10.jpg\");\n"
"background-repeat: no-repeat;\n"
"background-position: center;"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 1, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Avenir LT Std 65 Medium"));
        font.setPointSize(26);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"margin: 10px;"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        GameLauncherClass->setCentralWidget(centralWidget);

        retranslateUi(GameLauncherClass);

        QMetaObject::connectSlotsByName(GameLauncherClass);
    } // setupUi

    void retranslateUi(QMainWindow *GameLauncherClass)
    {
        GameLauncherClass->setWindowTitle(QApplication::translate("GameLauncherClass", "GameLauncher", nullptr));
#ifndef QT_NO_WHATSTHIS
        scrollArea->setWhatsThis(QApplication::translate("GameLauncherClass", "Counter-Strike", nullptr));
#endif // QT_NO_WHATSTHIS
#ifndef QT_NO_ACCESSIBILITY
        pushButton->setAccessibleName(QApplication::translate("GameLauncherClass", "Counter-Strike", nullptr));
#endif // QT_NO_ACCESSIBILITY
        pushButton->setText(QString());
        label->setText(QApplication::translate("GameLauncherClass", "Library", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameLauncherClass: public Ui_GameLauncherClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMELAUNCHER_H
