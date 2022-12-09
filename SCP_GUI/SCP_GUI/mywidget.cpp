#include "mywidget.h"
#include "ui_mywidget.h"

#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QStackedWidget>
#include <QVBoxLayout>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    QComboBox * scp_combox = new QComboBox(this);
    scp_combox->addItems({"Traffic", "Player", "EnvironmentAction", "TrafficLight", "Set", "Animator"});

    QWidget *trafficPageWidget = new QWidget;
    QWidget *playerPageWidget = new QWidget;
    QWidget *environmentAction = new QWidget;
    QWidget *trafficLightPageWidget = new QWidget;
    QWidget *setPageWidget = new QWidget;
    QWidget *animatorPageWidget = new QWidget;
    QStackedWidget * stackedWidget = new QStackedWidget(this);
//    stackedWidget->addWidget(trafficPageWidget);
//    stackedWidget->addWidget(playerPageWidget);
//    stackedWidget->addWidget(environmentAction);
//    stackedWidget->addWidget(trafficLightPageWidget);
//    stackedWidget->addWidget(setPageWidget);
//    stackedWidget->addWidget(animatorPageWidget);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(scp_combox);
    layout->addWidget(stackedWidget);
    setLayout(layout);
    connect(scp_combox, SIGNAL(activated(int)),
            stackedWidget, SLOT(setCurrentIndex(int)));


//    QLabel *traffic_label = new QLabel(trafficPageWidget);
//    traffic_label->setText("1235555555555555555555555555");
//    traffic_label->move(50,50);
    QGroupBox *trafficGroupBox = new QGroupBox(trafficPageWidget);
    trafficGroupBox->setCheckable(true);
    stackedWidget->addWidget(trafficGroupBox);

    stackedWidget->addWidget(playerPageWidget);
    stackedWidget->addWidget(environmentAction);
    stackedWidget->addWidget(trafficLightPageWidget);
    stackedWidget->addWidget(setPageWidget);
    stackedWidget->addWidget(animatorPageWidget);

    //    traffic->ActionSpeedChange节点内容
    QLineEdit *actorLineEdite = new QLineEdit(this);
    QLabel *actorLabel = new QLabel("actor", this);
    actorLabel->setBuddy(actorLineEdite);

    QLineEdit *targetLineEdite = new QLineEdit(this);
    QLabel *targetLabel = new QLabel(tr("target"), this);
    targetLabel->setBuddy(targetLineEdite);

    QLineEdit *rateLineEdite = new QLineEdit(this);
    QLabel *rateLabel = new QLabel("rate", this);
    targetLabel->setBuddy(rateLineEdite);

    QGridLayout *trafficGridLayout = new QGridLayout(this);

    trafficGridLayout->addWidget(actorLabel,0,0,1,1);
    trafficGridLayout->addWidget(actorLineEdite,0,1,1,1);

    trafficGridLayout->addWidget(targetLabel,1,0,1,1);
    trafficGridLayout->addWidget(targetLineEdite,1,1,1,1);

    trafficGridLayout->addWidget(rateLabel,2,0,1,1);
    trafficGridLayout->addWidget(rateLineEdite,2,1,1,1);

    trafficGroupBox->setLayout(trafficGridLayout);

//trafficPageWidget->




}

MyWidget::~MyWidget()
{
    delete ui;
}

