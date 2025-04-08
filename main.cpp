#include "mainwindow.h"
#include <QFontDatabase>
#include <QApplication>
#include "stopwatch.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Stopwatch stopwatch;
    QObject::connect(&w,&MainWindow::sendStart,&stopwatch,&Stopwatch::timerStart);
    QObject::connect(&w,&MainWindow::sendStop,&stopwatch,&Stopwatch::timerStop);
    QObject::connect(&w,&MainWindow::sendClear,&stopwatch,&Stopwatch::timerClear);
    QObject::connect(&stopwatch,&Stopwatch::sendTime,&w,&MainWindow::timeChanged);
    QObject::connect(&w,&MainWindow::nextCirlce,&stopwatch,&Stopwatch::nextCircle);
    QObject::connect(&stopwatch,&Stopwatch::sendCircle,&w,&MainWindow::getCircleTime);
    w.show();
    return a.exec();
}
