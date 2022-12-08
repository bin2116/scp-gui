#include "mywidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
//    设置窗口标题
    w.setWindowTitle(QObject::tr("SCP GUI"));

    w.show();
    return a.exec();
}
