#include "DownloadMgr.h"
#include <QEventLoop>
#include <QtGui>
#include <QNetworkReply>
#include "downloadWidget.h"
#include <QFile>

DownloadMgr::DownloadMgr(QObject *parent) : QObject(parent)
{
//    static int iCount = 0;
//    m_iCount = iCount;
//    iCount++;
    mDownloadSizeAtPause = 0;
}


DownloadMgr::DownloadMgr(QString strUrl, QObject *parent) : QObject(parent)
{
    qNAM = new QNetworkAccessManager();
    this->strUrl = strUrl;
    mDownloadSizeAtPause = 0;

    //    static int iCount = 0;
    //    m_iCount = iCount;
    //    iCount++;
}

//void DownloadMgr::run()
//{
//}

void DownloadMgr::updateProgress(qint64 bytesReceived, qint64 bytesTotal)
{

    qDebug() << "mDownloadSizeAtPause:Received:Total" << mDownloadSizeAtPause << "::" <<bytesReceived <<"::" <<bytesTotal;
    outFile.write(currentDownload->readAll() );
    qint64 percentage = ((mDownloadSizeAtPause + bytesReceived) * 100 ) / (mDownloadSizeAtPause + bytesTotal);
    //qint64 percentage = ((mDownloadSizeAtPause + bytesReceived) * 100 ) / ( bytesTotal);
    qDebug() << "%%%%%%%%%%%" << percentage;
    emit updateStatus(percentage);
}

void DownloadMgr::cancelDownload()
{
     qDebug() << "cancelDownload";
     currentDownload->abort();
     outFile.close();
}

void DownloadMgr::downloadReadyRead()
{
    qDebug() << "DownloadMgr::downloadReadyRead";
    qDebug() << outFile.fileName();
    if (outFile.isOpen())
    {
        qDebug() << "DownloadMgr::downloadReadyRead - inside if";
        outFile.write(currentDownload->readAll());
    }
    qDebug() << "DownloadMgr::downloadReadyRead- end";
}


void DownloadMgr::downloadFinished()
{
    qDebug() << "downloadFinished";
    outFile.close();
    emit finishedDownload();
}

void DownloadMgr::setFileName(QString strName)
{
    qDebug() << "file Name:" << strName;
    QString strFileName = "/home/kalyan/" + strName;
    outFile.setFileName(strFileName);
}

void DownloadMgr::setUrl(QString strName)
{
    strUrl = strName;
    qDebug() << strUrl;
}

void DownloadMgr::startDownload(DownloadWidget *downloadWidget)
{
    qDebug() << "strat download of mgr";

    if (!outFile.open(QIODevice::WriteOnly))
    {
           fprintf(stderr, "Problem opening save file '%s' Error : %s\n",
                       qPrintable(outFile.fileName()),
                       qPrintable(outFile.errorString()));
           currentDownload->abort();
     }
    request = new QNetworkRequest(strUrl);
    currentDownload = qNAM->get(*request);

    connect(currentDownload, SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(updateProgress(qint64,qint64)),Qt::QueuedConnection);
    //connect(currentDownload,SIGNAL(downloadProgress(qint64,qint64)),this,SIGNAL((qint64,qint64)),Qt::QueuedConnection);
    //connect(currentDownload,SIGNAL(downloadProgress(qint64,qint64)),this,SIGNAL(updateStatus(qint64,qint64)),Qt::QueuedConnection);
    connect(currentDownload, SIGNAL(finished()),this,SLOT(downloadFinished()),Qt::QueuedConnection);
   // connect(currentDownload, SIGNAL(readyRead()),this,SLOT(downloadReadyRead()),Qt::QueuedConnection);

    connect(this,SIGNAL(updateStatus(qint64)),downloadWidget,SLOT(updateProgress(qint64)),Qt::QueuedConnection);
    connect(this, SIGNAL(finishedDownload()),downloadWidget,SLOT(downloadFinished()),Qt::QueuedConnection);

}

//void DownloadMgr::moveToThreadM(QThread* pThread) {
//    this->moveToThread(pThread);
//    qNAM->moveToThread(pThread);
//    outFile.moveToThread(pThread);
//}

void DownloadMgr::Pause()
{

    disconnect(currentDownload, SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(updateProgress(qint64,qint64)));
   // disconnect(currentDownload,SIGNAL(downloadProgress(qint64,qint64)),this,SIGNAL(updateStatus(qint64)));
    disconnect(currentDownload, SIGNAL(finished()),this,SLOT(downloadFinished()));
    //disconnect(currentDownload, SIGNAL(readyRead()),this,SLOT(downloadReadyRead()));
    currentDownload->abort();
    outFile.write(currentDownload->readAll());
}

void DownloadMgr::Resume()
{
    mDownloadSizeAtPause = outFile.size();

    QByteArray rangeHeaderValue = "bytes=" + QByteArray::number(mDownloadSizeAtPause) + "-";
    request->setRawHeader("Range",rangeHeaderValue);
    currentDownload = qNAM->get(*request);

    connect(currentDownload, SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(updateProgress(qint64,qint64)),Qt::QueuedConnection);
   // connect(currentDownload,SIGNAL(downloadProgress(qint64,qint64)),this,SIGNAL(updateStatus(qint64)),Qt::QueuedConnection);
    connect(currentDownload, SIGNAL(finished()),this,SLOT(downloadFinished()),Qt::QueuedConnection);
    //connect(currentDownload, SIGNAL(readyRead()),this,SLOT(downloadReadyRead()),Qt::QueuedConnection);
}

void DownloadMgr::setNAM(QNetworkAccessManager *qNAM)
{
    this->qNAM = qNAM;
}
