#include "mywidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SCP_GUI w;
//    设置窗口标题
    w.setWindowTitle(QObject::tr("SCP GUI"));

    w.show();
    return a.exec();
}
