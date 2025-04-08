#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent)
    : QObject{parent}
{
    time = QTime(0,0);
    circleTime = QTime(0,0);
    circleNum = 0;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout,this,&Stopwatch::timerSlot);
}

void Stopwatch::timerStart()
{
    timer->start(100);
}

void Stopwatch::timerStop()
{
    timer->stop();
}

void Stopwatch::timerClear()
{
    time.setHMS(0,0,0);
    circleTime.setHMS(0,0,0);
    circleNum = 0;
}

void Stopwatch::nextCircle()
{
    circleNum++;
    QString message = "Круг " + QString::number(circleNum) +
                      ", время: " + QString::number(circleTime.secsTo(time)) + " c";
    circleTime = time;
    emit sendCircle(message);
}

void Stopwatch::timerSlot()
{
    time = time.addMSecs(100);
    emit sendTime(time);
}
