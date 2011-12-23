#ifndef SENDER_H
#define SENDER_H
#include <QThread>

class Sender: public QThread
{
Q_OBJECT;
public:
  //  explicit Sender::Sender(QObject *parent);
    explicit Sender(QThread *parent = 0);
protected:
    void timerEvent(QTimerEvent *);
    void run();
signals:
    void sigSender();

};

#endif // SENDER_H
