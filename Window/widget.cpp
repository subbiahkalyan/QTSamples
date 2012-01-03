#include "wiget.h"

Wiget::Wiget(QWidget *parent)
    : QWidget(parent)
{

    QPushButton *button = new QPushButton("close",this);
    button->show();
    button->move(400,100);
    label = new QLabel(this);
    label->setGeometry(200,200,200,200);
    connect(button,SIGNAL(clicked()),this,SLOT(closeWindow()));

}

void Wiget::closeWindow()
{
   this->close();
}
