#include "mywidget.h"
#include "ui_mywidget.h"
#include "scpwidget.h"
#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QStackedWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QtDebug>

SCP_GUI::SCP_GUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
//    ui->setupUi(this);
//    resize(500,600);
    scpComBox = new QComboBox(this);
    scpComBox->addItems({tr("Traffic"), tr("Player"), tr("EnvironmentAction"), tr("TrafficLight"), tr("Set"), tr("Animator")});
    scpVLayout = new QVBoxLayout(this);
    scpWidget = new ScpWidget(this);

    connect(scpComBox, SIGNAL(activated(int)),
                scpWidget->stackedWidget, SLOT(setCurrentIndex(int)));

    messageTextEdit = new QTextEdit(this);
    cretMessageBtn = new QPushButton(("生成"),this);
    sendMessageBtn = new QPushButton(("发送"),this);
    hBtnsLayout = new QHBoxLayout;
    hBtnsLayout->addWidget(cretMessageBtn);
    hBtnsLayout->addWidget(sendMessageBtn);

    scpVLayout->addWidget(scpComBox);
    scpVLayout->addWidget(scpWidget);
    scpVLayout->addWidget(messageTextEdit);
    scpVLayout->addLayout(hBtnsLayout);
//    scpVLayout->setContentsMargins(0,0,0,0);
    scpVLayout->setSpacing(0);
//    scpVLayout->setMargin(0);


}

SCP_GUI::~SCP_GUI()
{
    delete ui;
}

