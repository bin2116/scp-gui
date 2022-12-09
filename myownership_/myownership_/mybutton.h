#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class MyButton : public QObject
{
    Q_OBJECT
public:
    explicit MyButton(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MYBUTTON_H
