#include <QtCore/QCoreApplication>
#include "Sender.h"
#include "Reciver.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Receiver receiver;
    Sender sender;

    QObject::connect(&sender,SIGNAL(sigSender()),&receiver,SLOT(sltReceive()));

    return a.exec();
}
