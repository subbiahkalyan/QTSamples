#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
//#include <QtGui>
//#include <QNetworkReply>
//#include <QNetworkRequest>
//#include <QThread>
#include "downloadWidget.h"
#include "DownloadMgr.h"

//void MyThread::run() {
//    exec();
//}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qNetworkAccessMgr = new QNetworkAccessManager();

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(StartDownload()));
}

MainWindow::~MainWindow()
{
    delete qNetworkAccessMgr;
    delete ui;
}
//Q_DECLARE_METATYPE (DownloadWidget *);
void MainWindow::StartDownload()
{

   // qRegisterMetaType<DownloadWidget *> ();
    qDebug() << "StartDownload()";

    DownloadWidget *downloadWidget = new DownloadWidget();
    downloadWidget->setWindowTitle(ui->textEdit->toPlainText());
    downloadWidget->show();

    //MyThread *thread = new MyThread();
    DownloadMgr *dMgr = new DownloadMgr(ui->textEdit->toPlainText());
    dMgr->setNAM(qNetworkAccessMgr);
   // dMgr->moveToThreadM(thread);
    dMgr->setFileName(ui->fileName->toPlainText());
    //connect(this,SIGNAL(start(DownloadWidget *)),dMgr,SLOT(startDownload(DownloadWidget *)),Qt::QueuedConnection);

   // thread->start();
    connect(downloadWidget,SIGNAL(pauseDownload()),dMgr,SLOT(Pause()));
    connect(downloadWidget,SIGNAL(resumeDownload()),dMgr,SLOT(Resume()));

    dMgr->startDownload(downloadWidget);

   // QMetaObject::invokeMethod(dMgr, "run", Qt::QueuedConnection);
    //QMetaObject::invokeMethod(dMgr, "startDownload", Qt::QueuedConnection, Q_ARG(DownloadWidget *, downloadWidget));

}
