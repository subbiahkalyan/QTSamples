#include "Widget.h"

WebView::WebView(QWidget *parent):
        QWebView(parent)
{
    strName = "newWebView";
    QWebFrame *frame = this->page()->mainFrame();
    frame->addToJavaScriptWindowObject("kalyan", this);
}

QString WebView::getWebViewName()
{
    //emit callhello();
    return strName;
}

