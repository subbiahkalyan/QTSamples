#include "downloader.h"
#include "ftpview.h"
#include "NetworkAccessManager.h"

FtpView::FtpView()
{
    QNetworkAccessManager *oldManager = page()->networkAccessManager();
    NetworkAccessManager *newManager = new NetworkAccessManager(oldManager, this);
    page()->setNetworkAccessManager(newManager);

    page()->setForwardUnsupportedContent(true);
    downloader = new Downloader(this, newManager);

    connect(page(), SIGNAL(unsupportedContent(QNetworkReply *)),
            downloader, SLOT(saveFile(QNetworkReply *)));
    connect(page(), SIGNAL(downloadRequested(const QNetworkRequest &)),
            downloader, SLOT(startDownload(const QNetworkRequest &)));

    connect(this, SIGNAL(urlChanged(const QUrl &)),
            this, SLOT(updateWindowTitle(const QUrl &)));
}

void FtpView::updateWindowTitle(const QUrl &url)
{
    setWindowTitle(tr("FTP Client - %1").arg(url.toString()));
}
