#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QDir>
#include <QHash>
#include <QObject>
#include <QUrl>

class QNetworkAccessManager;
class QNetworkRequest;
class QNetworkReply;
class QWidget;

class Downloader : public QObject
{
    Q_OBJECT

public:
    Downloader(QWidget *parentWidget, QNetworkAccessManager *manager);

public slots:
    QString chooseSaveFile(const QUrl &url);
    void startDownload(const QNetworkRequest &request);
    void saveFile(QNetworkReply *reply);
    void finishDownload();

private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QHash<QString, QString> downloads;
    QString path;
    QWidget *parentWidget;
};

#endif // DOWNLOADER_H
