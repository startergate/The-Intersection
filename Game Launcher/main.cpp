#include "GameLauncher.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) // Qt 애플리케이션을 VS로 만들면 기본으로 생성되는 파일입니다.
{
    QApplication a(argc, argv);
    GameLauncher w;
    w.show();
    return a.exec();
}