#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTime>
#include <QMainWindow>

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
signals:
    void sendStart();
    void sendStop();
    void sendClear();
    void nextCirlce();
public slots:
    void timeChanged(const QTime& time);
    void getCircleTime(const QString message);
private slots:
    void on_pb_start_stop_clicked();

    void on_pb_clear_clicked();

    void on_pb_cirlce_clicked();

private:
    Ui::MainWindow *ui;
    bool active;
};
#endif // MAINWINDOW_H
