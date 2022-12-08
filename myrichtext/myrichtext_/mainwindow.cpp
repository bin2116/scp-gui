#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextFrame>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTextDocument *document = ui->textEdit->document();   // 获取文档对象
    QTextFrame *rootFrame = document->rootFrame();        // 获取根框架
    QTextFrameFormat format;                              // 创建框架格式
    format.setBorderBrush(Qt::red);                       // 边界颜色
    format.setBorder(3);                                  // 边界宽度
    rootFrame->setFrameFormat(format);                    // 框架使用格式

    QTextFrameFormat frameFormat;
    frameFormat.setBackground(Qt::lightGray);                  // 设置背景颜色
    frameFormat.setMargin(10);                                 // 设置边距
    frameFormat.setPadding(5);                                 // 设置填衬
    frameFormat.setBorder(2);
    frameFormat.setBorderStyle(QTextFrameFormat::BorderStyle_Dotted); // 设置边框样式
    QTextCursor cursor = ui->textEdit->textCursor();                  // 获取光标
    cursor.insertFrame(frameFormat);                                  // 在光标处插入框架

    QAction *action_textFrame = new QAction(tr("框架"), this);
    connect(action_textFrame, &QAction::triggered, this, &MainWindow::showTextFrame);
    ui->mainToolBar->addAction(action_textFrame);      // 在工具栏添加动作


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTextBlock()          // 遍历文本块
{
    QTextDocument *document = ui->textEdit->document();
    QTextBlock block = document->firstBlock();         // 获取文档的第一个文本块
    for (int i = 0; i < document->blockCount(); i++) {
        qDebug() << tr("文本块%1，文本块首行行号为:%2，长度为:%3,内容为：")
                    .arg(i).arg(block.firstLineNumber()).arg(block.length())
                 << block.text();
        block = block.next();                         // 获取下一个文本块
    }
}

