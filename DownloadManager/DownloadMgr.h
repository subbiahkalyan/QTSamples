#ifndef DOWNLOADMGR_H
#define DOWNLOADMGR_H
#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QFile>
#include "downloadWidget.h"

class DownloadMgr : public QObject
{
    Q_OBJECT

private:
    QNetworkAccessManager *qNAM;
    QNetworkReply *currentDownload;
    QNetworkRequest *request;
     QFile outFile;
     QString strUrl;
    // int m_iCount;
     qint64 mDownloadSizeAtPause;

public:
    DownloadMgr(QObject *parent = 0);
    DownloadMgr(QString strUrl,QObject *parent = 0);
    void setFileName(QString strName);
    void setUrl(QString strName);
//    void moveToThreadM(QThread*);
    void setNAM(QNetworkAccessManager *qNAM);

public slots:
   // void run();
    void startDownload(DownloadWidget *downloadWidget);
    void Pause();
    void Resume();

signals:
    void updateStatus(qint64);
    void finishedDownload();

private slots:
    void cancelDownload();
    void updateProgress(qint64,qint64);
    void downloadReadyRead();
    void downloadFinished();

};

#endif // DOWNLOADMGR_H
