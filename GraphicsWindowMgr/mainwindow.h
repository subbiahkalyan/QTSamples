#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QGraphicsWebView>

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
    QGraphicsView *view;
    QGraphicsScene *scene;

private slots:
    void onPushButtonPressed();
    void onChangeZValuePressed();


};

#endif // MAINWINDOW_H
