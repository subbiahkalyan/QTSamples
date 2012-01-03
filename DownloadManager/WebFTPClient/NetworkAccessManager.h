#ifndef NETWORKACCESSMANAGER_H
#define NETWORKACCESSMANAGER_H

#include <QNetworkAccessManager>

class NetworkAccessManager : public QNetworkAccessManager
{
    Q_OBJECT

public:
    NetworkAccessManager(QNetworkAccessManager *oldManager, QObject *parent = 0);

protected:
    QNetworkReply *createRequest(Operation operation, const QNetworkRequest &request, QIODevice *device);
};

#endif // NETWORKACCESSMANAGER_H
