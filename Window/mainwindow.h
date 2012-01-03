#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "wiget.h"
#include <QMap>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
//      Wiget *w;
    QMap<QString,Wiget*> mapWidgets;

private:
    Ui::MainWindow *ui;


private slots:
   // void closeWindow();
    void pushButton_pressed();
    void changeZOrder();
};

#endif // MAINWINDOW_H
