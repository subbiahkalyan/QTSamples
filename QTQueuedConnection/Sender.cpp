
#include "Sender.h"
#include "QTimerEvent"

Sender::Sender(QObject *parent) : QObject(parent)
{
    startTimer(200);
}

void Sender::timerEvent(QTimerEvent *)
{
    static int icount = 0;
    icount++;

    qDebug("counter:%d",icount);

    if (icount == 3)
    {
        icount = 0;
        emit sigSender();
    }

}
