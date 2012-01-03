#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QUrl>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsWebView>
#include <QWebSettings>

static int i = 100;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    view = new QGraphicsView(scene);
    view->setFrameShape(QFrame::NoFrame);

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(onPushButtonPressed()));
    connect(ui->updateZValue,SIGNAL(clicked()),this,SLOT(onChangeZValuePressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onPushButtonPressed()
{

    const int width = 640;
    const int height = 480;

    QGraphicsWebView *webview = new QGraphicsWebView();

    webview->resize(width, height);
    webview->setZValue(i++);
    webview->load(QUrl(ui->textEdit->toPlainText()));

    scene->addItem(webview);

    view->resize(width, height);
    view->show();

}

void MainWindow::onChangeZValuePressed()
{
    qDebug() << "onChangeZValue";


    QList<QGraphicsItem*> items = view->items();
    QList<QGraphicsItem*>::Iterator iter = items.begin();
    QUrl url1,url2;

    for(; iter != items.end(); iter++)
    {

        QGraphicsItem *graphicsItem = *iter;
        QGraphicsWebView *webView = dynamic_cast<QGraphicsWebView*>(graphicsItem);

        if(webView)
        {
            qDebug() << "URL:" << ui->textEdit->toPlainText();

             url1 =  webView->url();
             url2 = QString(ui->textEdit->toPlainText() + "/");

            qDebug() << "Url of QGraphics Item(QWebView)" << url1.toString();
            qDebug() << "Url given by the User" << url2.toString();

            if ( url1 == url2)
            {
               qDebug() << "Match found";
               graphicsItem->setZValue(i++);
            }
        }
    }
}
