#include "mainwindow.h"
#include <QFontDatabase>
#include <QApplication>
#include "stopwatch.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
