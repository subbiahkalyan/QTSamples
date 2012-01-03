#ifndef FTPVIEW_H
#define FTPVIEW_H
#include <QWebView>

class Downloader;
class QNetworkAccessManager;

class FtpView : public QWebView
{
    Q_OBJECT

public:
    FtpView();

private slots:
    void updateWindowTitle(const QUrl &url);

private:
    Downloader *downloader;
};

#endif // FTPVIEW_H
