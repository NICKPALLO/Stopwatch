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
signals:
    void sendTime(const QTime& time);
    void sendCircle(const QString message);
public slots:
    void timerStart();
    void timerStop();
    void timerClear();
    void nextCircle();
private slots:
    void timerSlot();
private:
    int circleNum;
    QTime time;
    QTime circleTime;
    QTimer* timer;
};

#endif // STOPWATCH_H
