#ifndef FTPREPLY_H
#define FTPREPLY_H
#include <QNetworkReply>
#include <QStringList>
#include <QUrlInfo>
#include <QFtp>

class QFtp;

class FtpReply : public QNetworkReply
{
    Q_OBJECT

public:
    FtpReply(const QUrl &url);
    void abort();
    qint64 bytesAvailable() const;
    bool isSequential() const;

protected:
    qint64 readData(char *data, qint64 maxSize);

private slots:
    void processCommand(int command, bool error);
    void processListInfo(const QUrlInfo &urlInfo);
    void processData();

private:
    void setContent();
    void setListContent();

    QFtp *ftp;
    QList<QUrlInfo> items;
    QByteArray content;
    qint64 offset;
    QStringList units;
};

#endif // FTPREPLY_H
