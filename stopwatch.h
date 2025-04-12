#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <QTime>

class Stopwatch : public QObject
{
    Q_OBJECT
public:
    explicit Stopwatch(QObject *parent = nullptr);
    void timerStart();
    void timerStop();
    void timerClear();
    QString nextCircle();
signals:
    void sendTime(const QTime& time);
private slots:
    void timerSlot();
private:
    int circleNum;
    QTime time;
    QTime circleTime;
    QTimer* timer;
};

#endif // STOPWATCH_H
