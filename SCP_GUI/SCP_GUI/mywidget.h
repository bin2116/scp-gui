#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QVBoxLayout>
#include <QPushButton>
#include "scpwidget.h"
#include <QTextEdit>


QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class SCP_GUI : public QWidget
{
    Q_OBJECT

public:
    SCP_GUI(QWidget *parent = nullptr);
    ~SCP_GUI();

    QComboBox *scpComBox;
    QVBoxLayout * scpVLayout;
    ScpWidget *scpWidget;
    QTextEdit *messageTextEdit;
    QPushButton * cretMessageBtn;
    QPushButton * sendMessageBtn;
    QHBoxLayout * hBtnsLayout;


private:
    Ui::MyWidget *ui;
};
#endif // MYWIDGET_H
