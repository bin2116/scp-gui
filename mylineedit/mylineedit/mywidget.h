#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private slots:
    void on_lineEdit2_returnPressed();

    void on_lineEdit3_returnPressed();

private:
    Ui::MyWidget *ui;
};
#endif // MYWIDGET_H
