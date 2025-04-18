#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTime>
#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void timeChanged(const QTime& time);
private slots:
    void on_pb_start_stop_clicked();

    void on_pb_clear_clicked();

    void on_pb_cirlce_clicked();

private:
    Ui::MainWindow *ui;
    bool active;
    Stopwatch* stopwatch;
};
#endif // MAINWINDOW_H
