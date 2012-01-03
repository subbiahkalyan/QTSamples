#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "wiget.h"
#include <QtGui>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(pushButton_pressed()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(changeZOrder()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::pushButton_pressed()
{

     static int i = 96;
     i++;
     Wiget *widget = new Wiget();
     QString str1("kalyan");
     QString str2(i);
     widget->setWindowTitle(str1 + "----" + str2);
     widget->setGeometry(500,500,500,500);
     widget->show();
     widget->label->setText("<h3>"+str2+"</h3>");
     mapWidgets[str2] = widget;
     qDebug() << "button pressed - new";

}

void MainWindow::changeZOrder()
{
   QString str= ui->textEdit->toPlainText();
   if(mapWidgets[str])
       mapWidgets[str]->raise();
   qDebug() << str;

}

//void MainWindow::closeWindow()
//{
//    w->close();
//    qDebug() << "pressed - close";
//}
