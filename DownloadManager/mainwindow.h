#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include "downloadWidget.h"

//class MyThread: public QThread {
//protected:
//    void run();
//};


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *qNetworkAccessMgr;

private slots:
    void StartDownload();

signals:
void start(DownloadWidget *);

};
#endif // MAINWINDOW_H
