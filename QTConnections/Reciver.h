#ifndef RECIVER_H
#define RECIVER_H
#include <QObject>

class Receiver: public QObject
{
Q_OBJECT;
public:

    explicit Receiver(QObject *parent = 0);

public slots:
    void sltReceive();

};

#endif // RECIVER_H
