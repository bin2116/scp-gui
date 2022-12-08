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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyWidget
{
public:
    QLineEdit *lineEdit1;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit4;

    void setupUi(QWidget *MyWidget)
    {
        if (MyWidget->objectName().isEmpty())
            MyWidget->setObjectName(QString::fromUtf8("MyWidget"));
        MyWidget->resize(800, 600);
        lineEdit1 = new QLineEdit(MyWidget);
        lineEdit1->setObjectName(QString::fromUtf8("lineEdit1"));
        lineEdit1->setGeometry(QRect(90, 60, 113, 20));
        lineEdit1->setEchoMode(QLineEdit::Password);
        lineEdit2 = new QLineEdit(MyWidget);
        lineEdit2->setObjectName(QString::fromUtf8("lineEdit2"));
        lineEdit2->setGeometry(QRect(90, 110, 113, 20));
        lineEdit3 = new QLineEdit(MyWidget);
        lineEdit3->setObjectName(QString::fromUtf8("lineEdit3"));
        lineEdit3->setGeometry(QRect(90, 160, 113, 20));
        label = new QLabel(MyWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 50, 71, 31));
        label_2 = new QLabel(MyWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 100, 61, 31));
        label_3 = new QLabel(MyWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 155, 71, 30));
        label_4 = new QLabel(MyWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 205, 71, 30));
        lineEdit4 = new QLineEdit(MyWidget);
        lineEdit4->setObjectName(QString::fromUtf8("lineEdit4"));
        lineEdit4->setGeometry(QRect(90, 210, 113, 20));

        retranslateUi(MyWidget);

        QMetaObject::connectSlotsByName(MyWidget);
    } // setupUi

    void retranslateUi(QWidget *MyWidget)
    {
        MyWidget->setWindowTitle(QApplication::translate("MyWidget", "MyWidget", nullptr));
        lineEdit2->setInputMask(QApplication::translate("MyWidget", ">AA-90-BB-! aa\\#H", nullptr));
        label->setText(QApplication::translate("MyWidget", "\346\230\276\347\244\272\346\250\241\345\274\217\357\274\232", nullptr));
        label_2->setText(QApplication::translate("MyWidget", "\350\276\223\345\205\245\346\216\251\347\240\201\357\274\232", nullptr));
        label_3->setText(QApplication::translate("MyWidget", "\350\276\223\345\205\245\351\252\214\350\257\201\357\274\232", nullptr));
        label_4->setText(QApplication::translate("MyWidget", "\350\207\252\345\212\250\345\256\214\346\210\220\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MyWidget: public Ui_MyWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
