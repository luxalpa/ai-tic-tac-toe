#include "MainWindow.h"
#include <QApplication>
#include <QTime>

int main(int argc, char *argv[])
{
    qsrand(QTime::currentTime().msec());

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
