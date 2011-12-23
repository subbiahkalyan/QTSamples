#include "Reciver.h"
#include "QDebug"
#include <QTime>

Receiver::Receiver(QObject *parent):QObject(parent)
{
}

void Receiver::sltReceive()
{
    QTime time = QTime::currentTime();

    qDebug("signal - Received: hour::min::sec::msec==>%d::%d::%d::%d",time.hour(),time.minute(),time.second(),time.msec());
}
