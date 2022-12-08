#ifndef MYACTION_H
#define MYACTION_H

#include <QWidget>

class QLineEdit;          // 前置声明
class MyAction : public QWidget
{
    Q_OBJECT

public:
    explicit MyAction(QWidget *parent = nullptr);
    QWidget* createWidget(QWidget *parent);

signals:
    void getText(const QString &string);


public slots:
    void sendText();
private:
    QLineEdit *lineEdit;

};

#endif // MYACTION_H
