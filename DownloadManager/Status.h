#ifndef STATUS_H
#define STATUS_H
#include <QWidget>
#include <QtGui>

class Status : public QWidget
{
    Q_OBJECT
public:
    Status(QWidget *parent= 0);
private slots:
    void closeWindow();
};

#endif // STATUS_H
