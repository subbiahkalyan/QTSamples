#include "downloadWidget.h"
//#include <QNetworkReply>
//#include <QNetworkRequest>
//#include <QEventLoop>


DownloadWidget::DownloadWidget(QWidget *parent)
    :QWidget(parent)
{
    progressBar = new QProgressBar(this);
    progressBar->setGeometry(40, 110, 250, 15);
    progressBar->show();
    progressBar->setValue(0);

    pauseButton = new QPushButton("Pause",this);
    pauseButton->show();
    pauseButton->move(350, 100);

    connect(pauseButton, SIGNAL(clicked()), this, SLOT(pauseButtonPressed()));

}

//void DownloadWidget::updateProgress(qint64 bytesReceived, qint64 bytesTotal)
//{
//    qDebug() << "Received:Total" <<bytesReceived <<":" <<bytesTotal;

//    progressBar->setValue(bytesReceived*100/bytesTotal);
//}

void DownloadWidget::updateProgress(qint64 percentage)
{
    qDebug() << "Received(%)" <<percentage;

    progressBar->setValue(percentage);
}

void DownloadWidget::pauseButtonPressed()
{
     qDebug() << "pauseButtonPressed";

    if (pauseButton->text() == QString("Pause"))
    {
        qDebug() << "Pause";
        pauseButton->setText("Resume");
        emit this->pauseDownload();
    }
    else if (pauseButton->text() == QString("Resume"))
    {
        qDebug() << "Resume";
        pauseButton->setText("Pause");
        emit this->resumeDownload();
    }
}

//void DownloadWidget::downloadReadyRead()
//{
//    qDebug() << "downloadReadyRead";
///*
//    if (outFile.isOpen())
//    {
//        outFile.write(currentDownload->readAll());
//    }*/
//}


void DownloadWidget::downloadFinished()
{

    qDebug() << "downloadFinished";
    pauseButton->setText("Done");
}

void DownloadWidget::setFileName(QString strName)
{
    outFile.setFileName(QString ("/home/kalyan/") + strName);
}

void DownloadWidget::setCurrentDowload(QNetworkReply *reply)
{
    currentDownload = reply;
    if (!outFile.open(QIODevice::WriteOnly))
    {
        fprintf(stderr, "Problem opening save file '%s' Error : %s\n",
                    qPrintable(outFile.fileName()),
                    qPrintable(outFile.errorString()));
    }
}

/*void DownloadWidget::run()
{
    QEventLoop eventLoop;
    qDebug() << "even loop stated";
    eventLoop.exec();
}*/
