/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QPushButton *pushBtn1;
    QPushButton *pushBtn2;
    QPushButton *pushBtn3;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QString::fromUtf8("MyWidget"));
        MyWidget->resize(800, 600);
        pushBtn1 = new QPushButton(MyWidget);
        pushBtn1->setObjectName(QString::fromUtf8("pushBtn1"));
        pushBtn1->setGeometry(QRect(50, 74, 91, 31));
        pushBtn1->setCheckable(true);
        pushBtn2 = new QPushButton(MyWidget);
        pushBtn2->setObjectName(QString::fromUtf8("pushBtn2"));
        pushBtn2->setGeometry(QRect(50, 109, 91, 31));
        pushBtn2->setFlat(true);
        pushBtn3 = new QPushButton(MyWidget);
        pushBtn3->setObjectName(QString::fromUtf8("pushBtn3"));
        pushBtn3->setGeometry(QRect(50, 150, 91, 31));

        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "MyWidget", nullptr));
        pushBtn1->setText(QApplication::translate("MyWidget", "pushBtn1", nullptr));
        pushBtn2->setText(QApplication::translate("MyWidget", "pushBtn2", nullptr));
        pushBtn3->setText(QApplication::translate("MyWidget", "pushBtn3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
