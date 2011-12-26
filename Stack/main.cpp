#include <QtCore/QCoreApplication>
#include "Stack.h"
#include <QDebug>

int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);

    Generic<int> intStack;
    intStack.pop();
    intStack.push(0);
    intStack.pop();
    intStack.pop();
    intStack.push(123);
    intStack.pop();

   return a.exec();
   }
