#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Секундомер");
    active = false;
    stopwatch = new Stopwatch(this);
    connect(stopwatch,&Stopwatch::sendTime,this,&MainWindow::timeChanged);
    connect(stopwatch, &Stopwatch::sendCircle,this,&MainWindow::getCircleTime);
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
        ui->pb_cirlce->setEnabled(false);
        ui->pb_start_stop->setText("Старт");
        stopwatch->timerStop();
    }
    else
    {
        active = true;
        ui->pb_cirlce->setEnabled(true);
        ui->pb_start_stop->setText("Стоп");
        stopwatch->timerStart();
    }
}


void MainWindow::on_pb_clear_clicked()
{
    stopwatch->timerClear();
    ui->tb_result->clear();
    ui->label_time->setText("00:00:00:0");
}


void MainWindow::on_pb_cirlce_clicked()
{
    if (active)
    {
        stopwatch->nextCircle();
    }
}

