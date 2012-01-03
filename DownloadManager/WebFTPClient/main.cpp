#include <QtGui/QApplication>
#include <QtWebKit>

#include "ftpview.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FtpView view;
    view.setUrl(QUrl("ftp://ftp.qt.nokia.com/qtsdk/"));
    view.show();

    return app.exec();
}
