#include "mywidget.h"
#include "ui_mywidget.h"

#include <QComboBox>
#include <QStackedWidget>
#include <QVBoxLayout>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    QWidget *trafficPageWidget = new QWidget;
    QWidget *playerPageWidget = new QWidget;
    QWidget *environmentAction = new QWidget;
    QWidget *trafficLightPageWidget = new QWidget;
    QWidget *setPageWidget = new QWidget;
    QWidget *animatorPageWidget = new QWidget;
    QStackedWidget * stackedWidget = new QStackedWidget();
    stackedWidget->addWidget(trafficPageWidget);
    stackedWidget->addWidget(playerPageWidget);
    stackedWidget->addWidget(environmentAction);
    stackedWidget->addWidget(trafficLightPageWidget);
    stackedWidget->addWidget(setPageWidget);
    stackedWidget->addWidget(animatorPageWidget);

    QVBoxLayout *layout = new QVBoxLayout;
         layout->addWidget(stackedWidget);
         setLayout(layout);

    QComboBox * scp_combox = new QComboBox(this);
    scp_combox->addItems({"Traffic", "Player", "EnvironmentAction", "TrafficLight", "Set", "Animator"});

    connect(scp_combox, SIGNAL(activated(int)),
                  stackedWidget, SLOT(setCurrentIndex(int)));


}

MyWidget::~MyWidget()
{
    delete ui;
}

