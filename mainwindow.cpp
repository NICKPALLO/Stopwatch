#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Секундомер");
    active = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeChanged(const QTime& time)
{
    ui->label_time->setText(time.toString("hh:mm:ss:z"));
}

void MainWindow::getCircleTime(const QString message)
{
    ui->tb_result->append(message);
}

void MainWindow::on_pb_start_stop_clicked()
{
    if (active)
    {
        active = false;
        ui->pb_start_stop->setText("Старт");
        emit sendStop();
    }
    else
    {
        active = true;
        ui->pb_start_stop->setText("Стоп");
        emit sendStart();
    }
}


void MainWindow::on_pb_clear_clicked()
{
    emit sendClear();
    ui->tb_result->clear();
    ui->label_time->setText("00:00:00:0");
}


void MainWindow::on_pb_cirlce_clicked()
{
    if (active)
    {
        emit nextCirlce();
    }
}

