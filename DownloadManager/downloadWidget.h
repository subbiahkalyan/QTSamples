#ifndef DOWNLOADWIDGET_H
#define DOWNLOADWIDGET_H
#include <QtGui>
#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>

class DownloadWidget : public QWidget
{
    Q_OBJECT

public:

    DownloadWidget(QWidget *parent= 0);
    void setFileName(QString strName);
    void setCurrentDowload(QNetworkReply *reply);
   // void run();

private:
    QNetworkAccessManager *qNetworkAccessMgr;
    QProgressBar *progressBar;
    QPushButton *pauseButton;
    QNetworkReply *currentDownload;
    QFile outFile;

signals:
void pauseDownload();
void resumeDownload();

private slots:
    void pauseButtonPressed();
    void updateProgress(qint64);
    //void downloadReadyRead();
    void downloadFinished();
};

#endif // DOWNLOADWIDGET_H
