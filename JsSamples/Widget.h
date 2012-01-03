#ifndef WIDGET_H
#define WIDGET_H
#include <QtWebKit>

class WebView : public QWebView
{
    Q_OBJECT
    QString strName;

public:
    explicit WebView(QWidget *parent = 0);

signals:
    void callhello();

public slots:
    QString getWebViewName();
};

#endif // WIDGET_H
