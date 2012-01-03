#include "Status.h"
#include <QProgressBar>

Status::Status(QWidget *parent)
    : QWidget(parent)
{

    QProgressBar *stBar = new QProgressBar(this);

    QLabel *label = new QLabel(this);
    label->setText("status bar");
    //stBar->addPermanentWidget(label, 200);
    stBar->show();


    QPushButton *button = new QPushButton("cancel",this);
    button->show();
    button->move(400,100);
    connect(button,SIGNAL(clicked()),this,SLOT(closeWindow()));

}

void Status::closeWindow()
{
   this->close();
}

