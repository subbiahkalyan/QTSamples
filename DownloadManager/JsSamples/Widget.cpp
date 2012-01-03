#include "Widget.h"
#include <QFtp>


WebView::WebView(QWidget *parent):
        QWebView(parent)
{
    strName = "newWebView";
    QWebFrame *frame = this->page()->mainFrame();
    frame->addToJavaScriptWindowObject("kalyan", this);
    QFtp *ftp = new QFtp();
    ftp->mkdir("/home/kalyan/ftptest");
}

QString WebView::getWebViewName()
{
    //emit callhello();
    return strName;
}

