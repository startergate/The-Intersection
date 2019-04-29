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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameLauncherClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QMainWindow *GameLauncherClass)
    {
        if (GameLauncherClass->objectName().isEmpty())
            GameLauncherClass->setObjectName(QString::fromUtf8("GameLauncherClass"));
        GameLauncherClass->resize(1032, 765);
        centralWidget = new QWidget(GameLauncherClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font;
        font.setFamily(QString::fromUtf8("Noto Sans KR Light"));
        pushButton->setFont(font);

        horizontalLayout->addWidget(pushButton);

        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setFont(font);

        horizontalLayout->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setFont(font);

        horizontalLayout->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setFont(font);

        horizontalLayout->addWidget(pushButton_6);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font);

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setFont(font);

        horizontalLayout->addWidget(pushButton_3);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        GameLauncherClass->setCentralWidget(centralWidget);

        retranslateUi(GameLauncherClass);

        QMetaObject::connectSlotsByName(GameLauncherClass);
    } // setupUi

    void retranslateUi(QMainWindow *GameLauncherClass)
    {
        GameLauncherClass->setWindowTitle(QApplication::translate("GameLauncherClass", "GameLauncher", nullptr));
        pushButton->setText(QApplication::translate("GameLauncherClass", "\353\235\274\354\235\264\353\270\214\353\237\254\353\246\254", nullptr));
        pushButton_4->setText(QApplication::translate("GameLauncherClass", "\353\235\274\354\235\264\353\270\214\353\237\254\353\246\254", nullptr));
        pushButton_5->setText(QApplication::translate("GameLauncherClass", "\353\235\274\354\235\264\353\270\214\353\237\254\353\246\254", nullptr));
        pushButton_6->setText(QApplication::translate("GameLauncherClass", "\353\235\274\354\235\264\353\270\214\353\237\254\353\246\254", nullptr));
        pushButton_2->setText(QApplication::translate("GameLauncherClass", "\353\235\274\354\235\264\353\270\214\353\237\254\353\246\254", nullptr));
        pushButton_3->setText(QApplication::translate("GameLauncherClass", "\353\235\274\354\235\264\353\270\214\353\237\254\353\246\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GameLauncherClass: public Ui_GameLauncherClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMELAUNCHER_H
