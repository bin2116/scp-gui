#include "scpwidget.h"

ScpWidget::ScpWidget(QWidget *parent) : QWidget(parent)
{

}

void ScpWidget::initTrafficWidget()
{
    trafficWidget = new QWidget(stackedWidget);

    //1. traffic->ActionSpeedChange节点内容
    actSpdChgGroupBox = new QGroupBox(tr("变速"),trafficWidget);
    actorLineEdite = new QLineEdit(trafficWidget);
    targetLineEdite = new QLineEdit(trafficWidget);
    rateLineEdite = new QLineEdit(trafficWidget);

    actSpdChgLayout = new QFormLayout(actSpdChgGroupBox);

    actSpdChgLayout->addRow(tr("实体id"),actorLineEdite);
    actSpdChgLayout->addRow(tr("目标速度"),targetLineEdite);
    actSpdChgLayout->addRow(tr("最大加速度"),rateLineEdite);

    //2. traffic->ActionRelativeSpeedChange节点内容
    actRelSpdChgGroupBox = new QGroupBox(tr("相对变速"),trafficWidget);
    actorLineEdite2 = new QLineEdit(trafficWidget);
    relativeactorLineEdite = new QLineEdit(trafficWidget);
    targetLineEdit = new QLineEdit(trafficWidget);
    ratetLineEdit2 = new QLineEdit(trafficWidget);

    actRelSpdChgLayout = new QFormLayout(actRelSpdChgGroupBox);

    actRelSpdChgLayout->addRow(tr("实体id"),actorLineEdite2);
    actRelSpdChgLayout->addRow(tr("相对实体id"),relativeactorLineEdite);
    actRelSpdChgLayout->addRow(tr("相对目标的速度"),targetLineEdit);
    actRelSpdChgLayout->addRow(tr("加速度"),ratetLineEdit2);

    //3. traffic->ActionLaneChange节点内容
    actLaneChgGroupBox = new QGroupBox("变道",trafficWidget);

    actLineEdite3 = new QLineEdit(actLaneChgGroupBox);
    timeLineEdit = new QLineEdit(actLaneChgGroupBox);
    valueLineEdit = new QLineEdit(actLaneChgGroupBox);

    actLaneChgLayout = new QFormLayout(actLaneChgGroupBox);
    actLaneChgLayout->addRow(tr("实体id"),actLineEdite3);
    actLaneChgLayout->addRow(tr("变道时间"),timeLineEdit);
    actLaneChgLayout->addRow(tr("变道数+(左换道)-(右换道)"),valueLineEdit);

    //4. traffic->ActionLongitudinalDistance节点内容
    actLongiDisGroupBox = new QGroupBox("纵向追车",trafficWidget);

    actorLineEdit4 = new QLineEdit(actLongiDisGroupBox);
    relativeactorLineEdit = new QLineEdit(actLongiDisGroupBox);
    distanceLineEdit = new QLineEdit(actLongiDisGroupBox);
    maxDecLineEdit = new QLineEdit(actLongiDisGroupBox);
    maxAccLineEdit = new QLineEdit(actLongiDisGroupBox);

    actLongiDisLayout = new QFormLayout(actLongiDisGroupBox);
    actLongiDisLayout->addRow(tr("实体id"),actorLineEdit4);
    actLongiDisLayout->addRow(tr("相对实体id"),relativeactorLineEdit);
    actLongiDisLayout->addRow(tr("纵向追车距离"),distanceLineEdit);
    actLongiDisLayout->addRow(tr("最大减速度"),maxDecLineEdit);
    actLongiDisLayout->addRow(tr("最大加速度"),maxAccLineEdit);

    //5. traffic->ActionLateralDistance节点内容
    actLateralDisGroupBox = new QGroupBox("横向追车",trafficWidget);

    actorLineEdit = new QLineEdit(actLateralDisGroupBox);
    relativeactorLineEdit5 = new QLineEdit(actLateralDisGroupBox);

    actLateralDisLayout = new QFormLayout(actLateralDisGroupBox);
    actLateralDisLayout->addRow(tr("实体id"),actorLineEdit);
    actLateralDisLayout->addRow(tr("相对实体id"),relativeactorLineEdit5);

    //6. traffic->TrafficSwarmAction节点内容
    trafficSwarmActGroupBox = new QGroupBox(tr("随机交通"),trafficWidget);
    trafficSwarmActGroupBox->setCheckable(true);
    centralActorLineEdit = new QLineEdit(this); //中心实体的id
    enableCombox = new QComboBox(this); //是否开启随机交通
    enableCombox->addItems({"false","true"});
    semiMinorAxisLineEdit = new QLineEdit(this); //短轴半径
    semiMajorAxisLineEdit = new QLineEdit(this);// 长轴半径
    offsetLineEdit = new QLineEdit(this); //中心偏移
    numberOfVehiclesLineEdit = new QLineEdit(this);

    trafficSwarmActLayout = new QFormLayout(trafficSwarmActGroupBox);
    trafficSwarmActLayout->addRow("中心实体的id",centralActorLineEdit);
    trafficSwarmActLayout->addRow("是否开启随机交通",enableCombox);
    trafficSwarmActLayout->addRow("长轴半径",semiMajorAxisLineEdit);
    trafficSwarmActLayout->addRow("短轴半径",semiMinorAxisLineEdit);
    trafficSwarmActLayout->addRow("中心偏移",offsetLineEdit);
    //7. traffic->TrafficSwarmReset
    trafficSwarmResetGroupBox = new QGroupBox(tr("重置随机交通"),trafficPageWidget);
    trafficSwarmResetGroupBox->setCheckable(true);
    //8. traffic->Pause


}

void ScpWidget::init_scpUi()
{
    scrollArea = new QScrollArea(this);
    stackedWidget = new QStackedWidget;

    scrollArea->setWidget(stackedWidget);
    scrollArea->setWidgetResizable(true);

    playerWidget = new QWidget(stackedWidget);
    envActWidget = new QWidget(stackedWidget);
    trafficLightWidget = new QWidget(stackedWidget);
    setWidget = new QWidget(stackedWidget);
    animatorWidget = new QWidget(stackedWidget);







}
