#ifndef STACK_H
#define STACK_H
#include "QDebug"
#include <QVector>
//#include <QObject>

template <class T>
class Generic
{

   QVector<T> vect;
   typename QVector<T>::Iterator topPtr;

   public:

   void push(T value);
   T pop();

} ;

template <class T>
T Generic<T>::pop()
{
    T value = T();
    if(vect.size() == 0)
    {
       qDebug() << "POP failed : WARNING - no elements in the stack";
       return value;
    }
    value = *topPtr;
    vect.erase(topPtr);
    --topPtr;
    qDebug() << "poped(" << value << ") from stack";
    //qDebug() << vect.size() << "stack size";
    return value;
}

template <class T>
void Generic<T>::push(T value)
{
   vect.append(value);
   topPtr = vect.begin() + vect.size() - 1;
   //qDebug() << vect.size() << "stack size";
   qDebug() << "pushed("<< *topPtr << ") into stack";
}

#endif // STACK_H
