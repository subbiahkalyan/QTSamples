
#include "Sender.h"
#include "QTimerEvent"
#include "qdebug.h"

#include  <QEventLoop>

Sender::Sender(QThread *parent) : QThread(parent)
{
    qDebug("sender - constructor");
    moveToThread(this);
    qDebug()  << "Sender thread id = " <<  QThread::currentThreadId();
}

void Sender::run()
{
    QEventLoop loop;
    startTimer(2000);
    loop.exec();
}

void Sender::timerEvent(QTimerEvent *)
{
    static int icount = 0;
    icount++;
    qDebug("counter:%d",icount);

    if (icount == 3)
    {
        icount = 0;
        qDebug()  << "Sender thread id = " <<  QThread::currentThreadId();
        emit sigSender();
    }

}
