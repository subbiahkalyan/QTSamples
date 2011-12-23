#include "Reciver.h"
#include "qdebug.h"

#include <QTime>
#include <QThread>

Receiver::Receiver(QObject *parent):QObject(parent)
{
}

void Receiver::sltReceive()
{
    QTime time = QTime::currentTime();
    qDebug()  << "Receiver thread id = " <<  QThread::currentThreadId();
    qDebug()  << "signal - Received:(hour:min:sec:msec)"
                           <<time.hour()<< ":"
                           <<time.minute()<< ":"
                           <<time.second()<< ":"
                           <<time.msec();
}
