//#include <QtCore/QCoreApplication>
#include <QtGui/QApplication>
#include <QtWebKit>
#include "Widget.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    WebView *w = new WebView();
    //w->load(QUrl("http://www.google.co.in"));
    w->load(QUrl("file:///home/kalyan/test.html"));
    w->show();

    return a.exec();
}
