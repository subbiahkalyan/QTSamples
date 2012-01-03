#include <QtNetwork>
#include "NetworkAccessManager.h"
#include "ftpreply.h"

NetworkAccessManager::NetworkAccessManager(QNetworkAccessManager *manager, QObject *parent)
    : QNetworkAccessManager(parent)
{
    setCache(manager->cache());
    setCookieJar(manager->cookieJar());
    setProxy(manager->proxy());
    setProxyFactory(manager->proxyFactory());
}

QNetworkReply *NetworkAccessManager::createRequest(
    QNetworkAccessManager::Operation operation, const QNetworkRequest &request,
    QIODevice *device)
{
    if (request.url().scheme() != "ftp")
        return QNetworkAccessManager::createRequest(operation, request, device);

    if (operation == GetOperation)
        // Handle ftp:// URLs separately by creating custom QNetworkReply
        // objects.
        return new FtpReply(request.url());
    else
        return QNetworkAccessManager::createRequest(operation, request, device);
}
