#include <QtCore/QCoreApplication>
#include "Sender.h"
#include "Reciver.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Receiver receiver;
    Sender *sender = new Sender();
    sender->start();

    QObject::connect(sender,SIGNAL(sigSender()),&receiver,SLOT(sltReceive()),Qt::QueuedConnection);

    return a.exec();
}
