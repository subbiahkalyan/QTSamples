#ifndef WIGET_H
#define WIGET_H
#include <QWidget>
#include <QtGui>

class Wiget : public QWidget
{
    Q_OBJECT
public:
    Wiget(QWidget *parent= 0);
    QLabel *label;
private slots:
    void closeWindow();
};

#endif // WIGET_H
