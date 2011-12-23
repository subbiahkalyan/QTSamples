#ifndef SENDER_H
#define SENDER_H
#include <QObject>

class Sender: public QObject
{
    Q_OBJECT;
public:
    explicit Sender(QObject *parent = 0);
protected:
    void timerEvent(QTimerEvent *);
signals:
    void sigSender();

};

#endif // SENDER_H
