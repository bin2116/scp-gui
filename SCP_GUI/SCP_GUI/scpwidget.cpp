#include "scpwidget.h"
#include <QDate>
#include <QDateTimeEdit>
#include<QDebug>

ScpWidget::ScpWidget(QWidget *parent) : QWidget(parent)
{
    init_scpUi();
}

void ScpWidget::initTrafficWidget()
{

    trafficWidget = new QWidget(stackedWidget);
    stackedWidget->addWidget(trafficWidget);
    //1. traffic->ActionSpeedChange节点内容
    actSpdChgGroupBox = new QGroupBox(tr("变速"),trafficWidget);
    actSpdChgGroupBox->setCheckable(true);
    actorLineEdite = new QLineEdit(trafficWidget);
    targetLineEdite = new QLineEdit(trafficWidget);
    rateLineEdite = new QLineEdit(trafficWidget);
    triggerLineEdite = new QLineEdit(trafficWidget);

    actSpdChgLayout = new QFormLayout(actSpdChgGroupBox);

    actSpdChgLayout->addRow(tr("实体id"),actorLineEdite);
    actSpdChgLayout->addRow(tr("目标速度"),targetLineEdite);
    actSpdChgLayout->addRow(tr("最大加速度"),rateLineEdite);
    actSpdChgLayout->addRow(tr("触发条件"),triggerLineEdite);

    //2. traffic->ActionRelativeSpeedChange节点内容
    actRelSpdChgGroupBox = new QGroupBox(tr("相对变速"),trafficWidget);
    actRelSpdChgGroupBox->setCheckable(true);
    actorLineEdite2 = new QLineEdit(trafficWidget);
    relativeactorLineEdite = new QLineEdit(trafficWidget);
    targetLineEdit = new QLineEdit(trafficWidget);
    ratetLineEdit2 = new QLineEdit(trafficWidget);
    triggerLineEdite2 = new QLineEdit(trafficWidget);

    actRelSpdChgLayout = new QFormLayout(actRelSpdChgGroupBox);

    actRelSpdChgLayout->addRow(tr("实体id"),actorLineEdite2);
    actRelSpdChgLayout->addRow(tr("相对实体id"),relativeactorLineEdite);
    actRelSpdChgLayout->addRow(tr("相对目标的速度"),targetLineEdit);
    actRelSpdChgLayout->addRow(tr("加速度"),ratetLineEdit2);
    actRelSpdChgLayout->addRow(tr("触发条件"),triggerLineEdite2);

    //3. traffic->ActionLaneChange节点内容
    actLaneChgGroupBox = new QGroupBox("变道",trafficWidget);
    actLaneChgGroupBox->setCheckable(true);
    actLineEdite3 = new QLineEdit(actLaneChgGroupBox);
    timeLineEdit = new QLineEdit(actLaneChgGroupBox);
    valueLineEdit = new QLineEdit(actLaneChgGroupBox);
    triggerLineEdite3 = new QLineEdit(actLaneChgGroupBox);

    actLaneChgLayout = new QFormLayout(actLaneChgGroupBox);
    actLaneChgLayout->addRow(tr("实体id"),actLineEdite3);
    actLaneChgLayout->addRow(tr("变道时间"),timeLineEdit);
    actLaneChgLayout->addRow(tr("变道数+(左换道)-(右换道)"),valueLineEdit);
    actLaneChgLayout->addRow(tr("触发条件"),triggerLineEdite3);

    //4. traffic->ActionLongitudinalDistance节点内容
    actLongiDisGroupBox = new QGroupBox("纵向追车",trafficWidget);
    actLongiDisGroupBox->setCheckable(true);
    actorLineEdit4 = new QLineEdit(actLongiDisGroupBox);
    relativeactorLineEdit = new QLineEdit(actLongiDisGroupBox);
    distanceLineEdit = new QLineEdit(actLongiDisGroupBox);
    maxDecLineEdit = new QLineEdit(actLongiDisGroupBox);
    maxAccLineEdit = new QLineEdit(actLongiDisGroupBox);
    triggerLineEdite4 = new QLineEdit(actLongiDisGroupBox);

    actLongiDisLayout = new QFormLayout(actLongiDisGroupBox);
    actLongiDisLayout->addRow(tr("实体id"),actorLineEdit4);
    actLongiDisLayout->addRow(tr("相对实体id"),relativeactorLineEdit);
    actLongiDisLayout->addRow(tr("纵向追车距离"),distanceLineEdit);
    actLongiDisLayout->addRow(tr("最大减速度"),maxDecLineEdit);
    actLongiDisLayout->addRow(tr("最大加速度"),maxAccLineEdit);
    actLongiDisLayout->addRow(tr("触发条件"),triggerLineEdite4);

    //5. traffic->ActionLateralDistance节点内容
    actLateralDisGroupBox = new QGroupBox("横向追车",trafficWidget);
    actLateralDisGroupBox->setCheckable(true);
    actorLineEdit = new QLineEdit(actLateralDisGroupBox);
    relativeactorLineEdit5 = new QLineEdit(actLateralDisGroupBox);
    triggerLineEdite5 = new QLineEdit(actLateralDisGroupBox);

    actLateralDisLayout = new QFormLayout(actLateralDisGroupBox);
    actLateralDisLayout->addRow(tr("实体id"),actorLineEdit);
    actLateralDisLayout->addRow(tr("相对实体id"),relativeactorLineEdit5);
    actLateralDisLayout->addRow(tr("触发条件"),triggerLineEdite5);

    //6. traffic->TrafficSwarmAction节点内容
    trafficSwarmActGroupBox = new QGroupBox(tr("随机交通"),trafficWidget);
    trafficSwarmActGroupBox->setCheckable(true);
    centralActorLineEdit = new QLineEdit(trafficSwarmActGroupBox); //中心实体的id
    enableCombox = new QComboBox(trafficSwarmActGroupBox); //是否开启随机交通
    enableCombox->addItems({"false","true"});
    semiMinorAxisLineEdit = new QLineEdit(trafficSwarmActGroupBox); //短轴半径
    semiMajorAxisLineEdit = new QLineEdit(trafficSwarmActGroupBox);// 长轴半径
    offsetLineEdit = new QLineEdit(trafficSwarmActGroupBox); //中心偏移
    numberOfVehiclesLineEdit = new QLineEdit(trafficSwarmActGroupBox);

    trafficSwarmActLayout = new QFormLayout(trafficSwarmActGroupBox);
    trafficSwarmActLayout->addRow("中心实体的id",centralActorLineEdit);
    trafficSwarmActLayout->addRow("是否开启随机交通",enableCombox);
    trafficSwarmActLayout->addRow("长轴半径",semiMajorAxisLineEdit);
    trafficSwarmActLayout->addRow("短轴半径",semiMinorAxisLineEdit);
    trafficSwarmActLayout->addRow("中心偏移",offsetLineEdit);
    trafficSwarmActLayout->addRow("中心偏移",numberOfVehiclesLineEdit);
    //7. traffic->TrafficSwarmReset
    trafficSwarmResetGroupBox = new QGroupBox(tr("重置随机交通"),trafficWidget);
    trafficSwarmResetGroupBox->setCheckable(true);
    //8. traffic->Pause
    pauseGroupBox = new QGroupBox(tr("交通流停止更新"),trafficWidget);
    pauseGroupBox->setCheckable(true);
    //9. traffic->Run
    runGroupBox = new QGroupBox(tr("交通流开始更新"),trafficWidget);
    runGroupBox->setCheckable(true);
    //10. traffic->ActionAutonomous
    QGroupBox *actAutoGroupBox = new QGroupBox(tr("激活实体的自动驾驶模式"),trafficWidget);
    actAutoGroupBox->setCheckable(true);

    actAutoLineEdit = new QLineEdit(actAutoGroupBox);
    triggerLineEdite6 = new QLineEdit(actAutoGroupBox);

    actAutoLayout = new QFormLayout(actAutoGroupBox);

    actAutoLayout->addRow("实体id",actAutoLineEdit);
    actAutoLayout->addRow("触发条件",triggerLineEdite6);

    //11. traffic->ActionTrajectory
    actTraGroupBox = new QGroupBox(tr("激活轨迹模式"),trafficWidget);
    actTraGroupBox->setCheckable(true);

    actorLineEdit11 = new QLineEdit(actTraGroupBox);
    desirSpdLineEdit11 = new QLineEdit(actTraGroupBox);
    trajectoryLineEdit11 = new QLineEdit(actTraGroupBox);
    triggerLineEdite7 = new QLineEdit(actTraGroupBox);

    actTraLayout = new QFormLayout(actTraGroupBox);
    actTraLayout->addRow("实体id",actorLineEdit11);
    actTraLayout->addRow("沿轨迹行驶的速度(默认5)",desirSpdLineEdit11);
    actTraLayout->addRow("库中轨迹的名称",trajectoryLineEdit11);
    actTraLayout->addRow("触发条件",triggerLineEdite7);

    //12. traffic->ActionPath
    actionPathGroupBox = new QGroupBox(tr("设置自动驾驶模式行驶路线"),trafficWidget);
    actionPathGroupBox->setCheckable(true);

    actorLineEdit12 = new QLineEdit(actionPathGroupBox);
    pathShapeLineEdit = new QLineEdit(actionPathGroupBox);
    triggerLineEdite8 = new QLineEdit(actionPathGroupBox);
    loopComBox = new QComboBox(actionPathGroupBox);
    loopComBox->addItems({"false","true"});

    actionPathLayout = new QFormLayout(actionPathGroupBox);
    actionPathLayout->addRow("实体id",actorLineEdit12);
    actionPathLayout->addRow("库中行驶路线的名称",pathShapeLineEdit);
    actionPathLayout->addRow("沿路线循环行驶",loopComBox);
    actionPathLayout->addRow("触发条件",triggerLineEdite8);

    //trafficWidget布局
    QVBoxLayout *trafficlayout = new QVBoxLayout(trafficWidget);
    trafficlayout->setAlignment(Qt::AlignTop);

    trafficlayout->addWidget(actSpdChgGroupBox);
    trafficlayout->addWidget(actRelSpdChgGroupBox);
    trafficlayout->addWidget(actLaneChgGroupBox);
    trafficlayout->addWidget(actLongiDisGroupBox);
    trafficlayout->addWidget(actLateralDisGroupBox);
    trafficlayout->addWidget(trafficSwarmActGroupBox);
    trafficlayout->addWidget(trafficSwarmResetGroupBox);
    trafficlayout->addWidget(pauseGroupBox);
    trafficlayout->addWidget(runGroupBox);
    trafficlayout->addWidget(actAutoGroupBox);
    trafficlayout->addWidget(actTraGroupBox);
    trafficlayout->addWidget(actionPathGroupBox);

}

void ScpWidget::initPlayerWidget()
{
    playerWidget = new QWidget(stackedWidget);
    stackedWidget->addWidget(playerWidget);

//    //Player属性
//    QLineEdit *idLineEdite = new QLineEdit(playerWidget);
//    idLayout = new QFormLayout(this);
//    idLayout->addRow("实体的id",idLineEdite);

    //1. Player->Delete
    deleteGroupBox = new QGroupBox(tr("删除实体(只能删除交通车)"),playerWidget);
    deleteGroupBox->setCheckable(true);
    idLineEdite1 = new QLineEdit(deleteGroupBox);

    deleteLayout = new QFormLayout(deleteGroupBox);
    deleteLayout->addRow("实体id",idLineEdite1);

    //2. Player->DriverBehavior
    driverBehaviorGroupBox = new QGroupBox(tr("修改实体的驾驶员模型(车辆才能生效)"),playerWidget);
    driverBehaviorGroupBox->setCheckable(true);

    idLineEdite2 = new QLineEdit(driverBehaviorGroupBox);
    desirFreSpdLineEdite = new QLineEdit(driverBehaviorGroupBox);
    desirCrosSpdLineEdite = new QLineEdit(driverBehaviorGroupBox);
    desirAccLineEdite = new QLineEdit(driverBehaviorGroupBox);
    desirDccLineEdite = new QLineEdit(driverBehaviorGroupBox);
    driverNameLineEdite = new QLineEdit(driverBehaviorGroupBox);

    driverBehaviorLayout = new QFormLayout(driverBehaviorGroupBox);
    driverBehaviorLayout->addRow("实体id",idLineEdite2);
    driverBehaviorLayout->addRow("自由行驶期望速度",desirFreSpdLineEdite);
    driverBehaviorLayout->addRow("通过路口期望速度",desirCrosSpdLineEdite);
    driverBehaviorLayout->addRow("舒适加速度",desirAccLineEdite);
    driverBehaviorLayout->addRow("舒适减速度",desirDccLineEdite);
    driverBehaviorLayout->addRow("库中驾驶员模型",driverNameLineEdite);

    //3. Player->Creat
    creatGroupBox = new QGroupBox(tr("创建实体"),playerWidget);
    creatGroupBox->setCheckable(true);

    idLineEdite3 = new QLineEdit(creatGroupBox);
    categoryComBox = new QComboBox(creatGroupBox);
    categoryComBox->addItems({"vehicle","pedestrian","object"});
    modelLineEdite = new QLineEdit(creatGroupBox);
    driverLineEdite = new QLineEdit(creatGroupBox);
    dxLineEdite = new QLineEdit(creatGroupBox);
    dyLineEdite = new QLineEdit(creatGroupBox);
    dzLineEdite = new QLineEdit(creatGroupBox);
    dhDegLineEdite = new QLineEdit(creatGroupBox);
    dpDegLineEdite = new QLineEdit(creatGroupBox);
    drDegLineEdite = new QLineEdit(creatGroupBox);

    creatLayout = new QFormLayout(creatGroupBox);
    creatLayout->addRow("实体id",idLineEdite3);
    creatLayout->addRow("新建实体的类别",categoryComBox);
    creatLayout->addRow("车辆3D模型名称",modelLineEdite);
    creatLayout->addRow("驾驶员模型名称",driverLineEdite);
    creatLayout->addRow("相对本车的x坐标",dxLineEdite);
    creatLayout->addRow("相对本车的y坐标",dyLineEdite);
    creatLayout->addRow("相对本车的z坐标",dzLineEdite);
    creatLayout->addRow("相对本车的h角度",dhDegLineEdite);
    creatLayout->addRow("相对本车的p角度",dpDegLineEdite);
    creatLayout->addRow("相对本车的r角度",drDegLineEdite);

    //4. Player->LeftTurnLight
    leftTurnLightGroupBox = new QGroupBox(tr("左转向灯"),playerWidget);
    leftTurnLightGroupBox->setCheckable(true);

    idLineEdite4 = new QLineEdit(leftTurnLightGroupBox);
    stateComBox = new QComboBox(leftTurnLightGroupBox);
    stateComBox->addItems({"0","1"});

    stateMaskComBox = new QComboBox(leftTurnLightGroupBox);
    stateMaskComBox->addItems({"0","1"});

    leftTurnLightLayout = new QFormLayout(leftTurnLightGroupBox);
    leftTurnLightLayout->addRow(tr("实体id"),idLineEdite4);
    leftTurnLightLayout->addRow(tr("状态"),stateComBox);
    leftTurnLightLayout->addRow(tr("覆盖自动转向状态"),stateMaskComBox);

    //5. Player->RightTurnLight
    rightTurnLightGroupBox = new QGroupBox(tr("右转向灯"),playerWidget);
    rightTurnLightGroupBox->setCheckable(true);

    idLineEdite5 = new QLineEdit(rightTurnLightGroupBox);
    stateComBox5 = new QComboBox(rightTurnLightGroupBox);
    stateComBox5->addItems({"0","1"});

    stateMaskComBox5 = new QComboBox(rightTurnLightGroupBox);
    stateMaskComBox5->addItems({"0","1"});

    rightTurnLightLayout = new QFormLayout(rightTurnLightGroupBox);
    rightTurnLightLayout->addRow(tr("实体id"),idLineEdite5);
    rightTurnLightLayout->addRow(tr("状态"),stateComBox5);
    rightTurnLightLayout->addRow(tr("覆盖自动转向状态"),stateMaskComBox5);

    //6. Player->HeadLight
    headLightGroupBox = new QGroupBox(tr("车头灯"),playerWidget);
    headLightGroupBox->setCheckable(true);

    idLineEdite6 = new QLineEdit(headLightGroupBox);
    stateComBox6 = new QComboBox(headLightGroupBox);
    stateComBox6->addItems({"0","1"});

    stateMaskComBox6 = new QComboBox(headLightGroupBox);
    stateMaskComBox6->addItems({"0","1"});

    headLightLayout = new QFormLayout(headLightGroupBox);
    headLightLayout->addRow(tr("实体id"),idLineEdite6);
    headLightLayout->addRow(tr("状态"),stateComBox6);
    headLightLayout->addRow(tr("覆盖自动头灯状态"),stateMaskComBox6);

    //7. Player->BrakeLight
    brakeLightGroupBox = new QGroupBox(tr("刹车灯"),playerWidget);
    brakeLightGroupBox->setCheckable(true);

    idLineEdite7 = new QLineEdit(brakeLightGroupBox);
    stateComBox7 = new QComboBox(brakeLightGroupBox);
    stateComBox7->addItems({"0","1"});

    stateMaskComBox7 = new QComboBox(brakeLightGroupBox);
    stateMaskComBox7->addItems({"0","1"});

    brakeLightLayout = new QFormLayout(brakeLightGroupBox);
    brakeLightLayout->addRow(tr("实体id"),idLineEdite7);
    brakeLightLayout->addRow(tr("状态"),stateComBox7);
    brakeLightLayout->addRow(tr("覆盖自动制动状态"),stateMaskComBox7);

    //8.Player->PositionAbsolute
    posAbsGroupBox = new QGroupBox(tr("设定交通车的绝对位置"),playerWidget);
    posAbsGroupBox->setCheckable(true);

    idLineEdite8 = new QLineEdit(posAbsGroupBox);
    xLineEdit = new QLineEdit(posAbsGroupBox);
    yLineEdit = new QLineEdit(posAbsGroupBox);
    zLineEdit = new QLineEdit(posAbsGroupBox);
    hDegLineEdit = new QLineEdit(posAbsGroupBox);

    posAbsLayout = new QFormLayout(posAbsGroupBox);
    posAbsLayout->addRow(tr("实体id"),idLineEdite8);
    posAbsLayout->addRow(tr("x坐标"),xLineEdit);
    posAbsLayout->addRow(tr("y坐标"),yLineEdit);
    posAbsLayout->addRow(tr("z坐标"),zLineEdit);
    posAbsLayout->addRow(tr("hDeg坐标"),hDegLineEdit);

    //9. Player->PositionRelative
    posRelGroupBox = new QGroupBox(tr("横向追车"),playerWidget);
    posRelGroupBox->setCheckable(true);

    idLineEdite9 = new QLineEdit(posRelGroupBox);
    actorLineEdit9 = new QLineEdit(posRelGroupBox);
    disLineEdit = new QLineEdit(posRelGroupBox);
    laneLineEdit = new QLineEdit(posRelGroupBox);
    offsetLineEdit9 = new QLineEdit(posRelGroupBox);
    dhDegLineEdit9 = new QLineEdit(posRelGroupBox);

    posRelLayout = new QFormLayout(posRelGroupBox);
    posRelLayout->addRow(tr("实体id"),idLineEdite9);
    posRelLayout->addRow(tr("相对实体id"),actorLineEdit9);
    posRelLayout->addRow(tr("相对实体的纵向距离"),disLineEdit);
    posRelLayout->addRow(tr("相对实体的车道id"),laneLineEdit);
    posRelLayout->addRow(tr("偏离车道的距离"),offsetLineEdit9);
    posRelLayout->addRow(tr("相对实体的方向角"),dhDegLineEdit9);

    //playerWidget布局
    QVBoxLayout *playerPagelayout = new QVBoxLayout(playerWidget);
    playerPagelayout->setAlignment(Qt::AlignTop);

    playerPagelayout->addWidget(deleteGroupBox);
    playerPagelayout->addWidget(driverBehaviorGroupBox);
    playerPagelayout->addWidget(creatGroupBox);
    playerPagelayout->addWidget(leftTurnLightGroupBox);
    playerPagelayout->addWidget(rightTurnLightGroupBox);
    playerPagelayout->addWidget(headLightGroupBox);
    playerPagelayout->addWidget(brakeLightGroupBox);
    playerPagelayout->addWidget(posAbsGroupBox);
    playerPagelayout->addWidget(posRelGroupBox);

//    playerWidget->setLayout(playerPagelayout);
}

void ScpWidget::initEnvactWidget()
{
    envActWidget = new QWidget(stackedWidget);
    stackedWidget->addWidget(envActWidget);

    //光照
    lightGroupBox = new QGroupBox("光照",envActWidget);
    lightGroupBox->setCheckable(true);

    sunTypeComBox = new QComboBox(lightGroupBox);
    sunTypeComBox->addItems({"太阳角度","日期时间"});

    envLayout = new QFormLayout;
    envLayout->addRow("配置方式",sunTypeComBox);

    sunTypeStackWidget = new QStackedWidget(lightGroupBox);
    lightWidget = new QWidget(sunTypeStackWidget);
    timeWidget = new QWidget(sunTypeStackWidget);
    sunTypeStackWidget->addWidget(lightWidget);
    sunTypeStackWidget->addWidget(timeWidget);

    connect(sunTypeComBox, SIGNAL(activated(int)),
            sunTypeStackWidget, SLOT(setCurrentIndex(int)));

    lightLayout = new QFormLayout;

    timeLayout = new QFormLayout;

    luxBox = new QDoubleSpinBox(lightWidget);
    luxBox->setMaximum(1000000);
    luxBox->setValue(8000);

    elevationBox = new QDoubleSpinBox(lightWidget);
    azimuthBox = new QDoubleSpinBox(lightWidget);
    lightLayout->addRow("光强  lux",luxBox);
    lightLayout->addRow("旋转角",azimuthBox);
    lightLayout->addRow("抬升角",elevationBox);

    dateEdit = new QDateTimeEdit(QDate::currentDate(), timeWidget);
    dateEdit->setDisplayFormat("yyyy-MM-dd");
    dateEdit->setCalendarPopup(true);
    timeEdit = new QDateTimeEdit(timeWidget);
    timeEdit->setDisplayFormat("HH:mm:ss");
    timeEdit->setDateTime(QDateTime::currentDateTime());

    timeFlowButton = new QRadioButton(timeWidget);
    timeLayout->addRow("日期",dateEdit);
    timeLayout->addRow("时间",timeEdit);
    timeLayout->addRow("时间流动",timeFlowButton);

    QVBoxLayout *lightVlayout = new QVBoxLayout(lightGroupBox);
    lightVlayout->addLayout(envLayout);
    lightVlayout->addWidget(sunTypeStackWidget);
    lightVlayout->setAlignment(Qt::AlignTop);

    QVBoxLayout *light_Vlayout = new QVBoxLayout(lightWidget);
    light_Vlayout->setContentsMargins(0,0,0,0);
    light_Vlayout->addLayout(lightLayout);
    QVBoxLayout *time_layout = new QVBoxLayout(timeWidget);
    time_layout->setContentsMargins(0,0,0,0);
    time_layout->addLayout(timeLayout);

    //云层
    cloudStateGroupBox = new QGroupBox("云层",envActWidget);
    cloudStateGroupBox->setCheckable(true);

    cloudStateComBox = new QComboBox(cloudStateGroupBox);
    cloudStateComBox->addItems({"天空关闭","晴天","多云",
                                "阴天","下雨"});
    cloudStateLayout = new QFormLayout(cloudStateGroupBox);
    cloudStateLayout->addRow("天气类型",cloudStateComBox);

    //雨雪
    rain_snow_GroupBox = new QGroupBox(tr("雨雪"),envActWidget);
    rain_snow_GroupBox->setCheckable(true);
    typeComBox = new QComboBox(rain_snow_GroupBox);
    typeComBox->addItems({"正常","雨","雪"});

    QHBoxLayout *slider_layout = new QHBoxLayout;
    value_slider = new QSlider(rain_snow_GroupBox);
    value_slider->setOrientation(Qt::Horizontal);
    value_slider->setMinimum(0);
    value_slider->setMaximum(100);
    value_slider->setSingleStep(1);

    value_edit = new QLineEdit("0");
    value_edit->setEnabled(false);
    value_edit->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    value_edit->setMaximumSize(23,23);

    percen_label = new QLabel("%");

    slider_layout->addWidget(value_slider);
    slider_layout->addWidget(value_edit);
    slider_layout->addWidget(percen_label);

    rain_snow_layout = new QFormLayout(rain_snow_GroupBox);
    rain_snow_layout->addRow("类型",typeComBox);
    rain_snow_layout->addRow("大小",slider_layout);

    // 雾/尘
    fog_dust_groupBox = new QGroupBox("雾/尘",envActWidget);
    fog_dust_groupBox->setCheckable(true);

    fog_dust_layout = new QFormLayout(fog_dust_groupBox);

    typeComBox2 = new QComboBox(fog_dust_groupBox);
    typeComBox2->addItems({"雾","尘","无"});

    rangeComboBox = new QComboBox(fog_dust_groupBox);
    rangeComboBox->addItems({"全局","局部"});

    visualRange = new QLineEdit(fog_dust_groupBox);

    xLineEdit2 = new QLineEdit(fog_dust_groupBox);
    yLineEdit2 = new QLineEdit(fog_dust_groupBox);
    zLineEdit2 = new QLineEdit(fog_dust_groupBox);

    lengthLineEdit = new QLineEdit(fog_dust_groupBox);
    widthLineEdit = new QLineEdit(fog_dust_groupBox);
    heightLineEdit = new QLineEdit(fog_dust_groupBox);

    fog_dust_layout->addRow("类型",typeComBox2);
    fog_dust_layout->addRow("范围",rangeComboBox);
    fog_dust_layout->addRow("可见度  m",visualRange);
    fog_dust_layout->addRow("中心x坐标",xLineEdit2);
    fog_dust_layout->addRow("中心y坐标",yLineEdit2);
    fog_dust_layout->addRow("中心z坐标",zLineEdit2);
    fog_dust_layout->addRow("box边长  m",lengthLineEdit);
    fog_dust_layout->addRow("box边宽  m",widthLineEdit);
    fog_dust_layout->addRow("box边高  m",heightLineEdit);

    //路面积水
    water_groupBox = new QGroupBox("路面积水",envActWidget);
    water_groupBox->setCheckable(true);

    water_layout = new QFormLayout(water_groupBox);

    type_comboBox = new QComboBox(water_groupBox);
    type_comboBox->addItems({"干燥","雨","雪"});

    QHBoxLayout *water_slider_layout = new QHBoxLayout;

    water_slider = new QSlider(water_groupBox);
    water_slider->setOrientation(Qt::Horizontal);
    water_slider->setMinimum(0);
    water_slider->setMaximum(100);
    water_slider->setSingleStep(1);

    value_edit2 = new QLineEdit("0");
    value_edit2->setEnabled(false);
    value_edit2->setStyleSheet("background:transparent;border-width:0;border-style:outset");
    value_edit2->setMaximumSize(23,23);

    percen_label2 = new QLabel("%");

    water_slider_layout->addWidget(water_slider);
    water_slider_layout->addWidget(value_edit2);
    water_slider_layout->addWidget(percen_label2);

    water_layout->addRow("类型",type_comboBox);
    water_layout->addRow("积水量",water_slider_layout);

    //路面摩擦
    fric_groupBox = new QGroupBox("路面摩擦",envActWidget);
    fric_groupBox->setCheckable(true);

    fric_layout = new QFormLayout(fric_groupBox);

    fric_comboBox = new QLineEdit("1",fric_groupBox);

    fric_layout->addRow("摩擦系数",fric_comboBox);

    //envActWidget布局
    QVBoxLayout *envVLayout = new QVBoxLayout(envActWidget);
    envVLayout->addWidget(lightGroupBox);
    envVLayout->addWidget(cloudStateGroupBox);
    envVLayout->addWidget(rain_snow_GroupBox);
    envVLayout->addWidget(fog_dust_groupBox);
    envVLayout->addWidget(water_groupBox);
    envVLayout->addWidget(fric_groupBox);
    envVLayout->addStretch(5);

}

void ScpWidget::initTrafficlightWidget()
{

    trafficLightWidget = new QWidget(stackedWidget);
    stackedWidget->addWidget(trafficLightWidget);

//    idLineEdite10 = new QLineEdit(trafficLightWidget);
//    idLayout2 = new QFormLayout(trafficLightWidget);
//    idLayout2->addRow(tr("交通灯的id"),idLineEdite10);
    //1.TrafficLight->SetState
    setStateGroupBox = new QGroupBox( tr("设置交通灯当前的状态"),trafficLightWidget);
    setStateGroupBox->setCheckable(true);

    stateComBox2 = new QComboBox(setStateGroupBox);
    stateComBox2->addItems({"stop","go","attention"});

    idLineEdite10 = new QLineEdit(setStateGroupBox);

    setStateLayout = new QFormLayout(setStateGroupBox);
    setStateLayout->addRow(tr("交通灯id"),idLineEdite10);
    setStateLayout->addRow(tr("状态"),stateComBox2);

    //2.TrafficLight->SetPhase
    setPhaseGroupBox = new QGroupBox( tr("设置交通灯的相位时长"),trafficLightWidget);
    setPhaseGroupBox->setCheckable(true);

    idLineEdite11 = new QLineEdit(setPhaseGroupBox);

    stateComBox3 = new QComboBox(setPhaseGroupBox);
    stateComBox3->addItems({"stop","go","attention"});

    durationLineEdite = new QLineEdit(setPhaseGroupBox);

    setPhaseLayout = new QFormLayout(setPhaseGroupBox);
    setPhaseLayout->addRow(tr("交通灯id"),idLineEdite11);
    setPhaseLayout->addRow(tr("相位"),stateComBox3);
    setPhaseLayout->addRow(tr("持续时间"),durationLineEdite);

    //trafficLightWidget布局
    QVBoxLayout *trafficLightLayout = new QVBoxLayout(trafficLightWidget);
    trafficLightLayout->setAlignment(Qt::AlignTop);
    trafficLightLayout->addWidget(setStateGroupBox);
    trafficLightLayout->addWidget(setPhaseGroupBox);
}

void ScpWidget::initSetWidget()
{
    setWidget = new QWidget(stackedWidget);
    stackedWidget->addWidget(setWidget);

    //Set->Trigger
    triggerGroupBox = new QGroupBox(tr("设置触发节点"),setWidget);
    triggerGroupBox->setCheckable(true);

    QWidget *owner_nmae_widget = new QWidget(triggerGroupBox);

    ownerLineEdite = new QLineEdit(owner_nmae_widget);
    nameLineEdite = new QLineEdit(owner_nmae_widget);


    owner_nmae_Layout =  new QFormLayout(owner_nmae_widget);
    owner_nmae_Layout->addRow("触发所有者",ownerLineEdite);
    owner_nmae_Layout->addRow("触发名称",nameLineEdite);

    //Set->Trigger->Delete
    deleteGroupBox2 = new QGroupBox("删除节点",triggerGroupBox);
    deleteGroupBox2->setCheckable(true);

    //Set->Trigger->PosAbsolute
    posAbsGroupBox2 = new QGroupBox("绝对位置触发",triggerGroupBox);
    posAbsGroupBox2->setCheckable(true);

    xLineEdite3 = new QLineEdit(posAbsGroupBox2);
    yLineEdite3 = new QLineEdit(posAbsGroupBox2);
    radiusLineEdite3 = new QLineEdit(posAbsGroupBox2);

    posAbsLayout2 = new QFormLayout(posAbsGroupBox2);
    posAbsLayout2->addRow(tr("x坐标"),xLineEdite3);
    posAbsLayout2->addRow(tr("y坐标"),yLineEdite3);
    posAbsLayout2->addRow(tr("半径"),radiusLineEdite3);

    //Set->Trigger->PosRelative
    posRelGroupBox3 = new QGroupBox("相对位置触发",triggerGroupBox);
    posRelGroupBox3->setCheckable(true);

    relActLineEdite = new QLineEdit(posRelGroupBox3);
    disLineEdite2 = new QLineEdit(posRelGroupBox3);

    posRelLayout3 = new QFormLayout(posRelGroupBox3);
    posRelLayout3->addRow(tr("参考实体id"),relActLineEdite);
    posRelLayout3->addRow(tr("几何距离"),disLineEdite2);

    //Set->Trigger->TTCRelative
    TTCRelGroupBox = new QGroupBox("相对碰撞触发",triggerGroupBox);
    TTCRelGroupBox->setCheckable(true);

    QLineEdit *relActLineEdite2 = new QLineEdit(TTCRelGroupBox);
    QLineEdit *timeLineEdite2 = new QLineEdit(TTCRelGroupBox);

    TTCRelLayout = new QFormLayout(TTCRelGroupBox);
    TTCRelLayout->addRow(tr("参考实体id"),relActLineEdite2);
    TTCRelLayout->addRow(tr("距离碰撞的时间"),timeLineEdite2);

    //Set->Trigger->THRelative
    THRelGroupBox = new QGroupBox("车头时距触发",triggerGroupBox);
    THRelGroupBox->setCheckable(true);

    relActLineEdite3 = new QLineEdit(THRelGroupBox);
    timeLineEdite3 = new QLineEdit(THRelGroupBox);

    THRelLayout = new QFormLayout(THRelGroupBox);
    THRelLayout->addRow(tr("参考实体id"),relActLineEdite3);
    THRelLayout->addRow(tr("车头时距"),timeLineEdite3);

    //Set->Trigger->Speed
    spdGroupBox = new QGroupBox("速度触发",triggerGroupBox);
    spdGroupBox->setCheckable(true);

    valueLineEdite2 = new QLineEdit(spdGroupBox);
    valueCheckBox = new QComboBox(spdGroupBox);
    valueCheckBox->addItems({"true","false"});

    spdLayout = new QFormLayout(spdGroupBox);
    spdLayout->addRow(tr("速度触发值"),valueLineEdite2);
    spdLayout->addRow(tr("超过该值时触发"),valueCheckBox);

    //setWidget布局
    QVBoxLayout *setPageLayout = new QVBoxLayout(setWidget);
    setPageLayout->addWidget(triggerGroupBox);
    setPageLayout->setAlignment(Qt::AlignTop);
    QVBoxLayout *triggerLayout = new QVBoxLayout(triggerGroupBox);
    triggerLayout->addWidget(owner_nmae_widget);
    triggerLayout->addWidget(deleteGroupBox2);
    triggerLayout->addWidget(posAbsGroupBox2);
    triggerLayout->addWidget(posRelGroupBox3);
    triggerLayout->addWidget(TTCRelGroupBox);
    triggerLayout->addWidget(THRelGroupBox);
    triggerLayout->addWidget(spdGroupBox);
}

void ScpWidget::initAnimatorWidget()
{
    animatorWidget = new QWidget(stackedWidget);
    stackedWidget->addWidget(animatorWidget);

    //1. Animator->PosistionRelative
    posRelGroupBox2 = new QGroupBox( tr("摄像头相对于主车的位置"),animatorWidget);
    posRelGroupBox2->setCheckable(true);

    idLineEdite12 = new QLineEdit(posRelGroupBox2);
    dxLineEdite2 = new QLineEdit(posRelGroupBox2);
    dyLineEdite2 = new QLineEdit(posRelGroupBox2);
    dzLineEdite2 = new QLineEdit(posRelGroupBox2);
    dhDegLineEdite2 = new QLineEdit(posRelGroupBox2);
    dpDegLineEdite2 = new QLineEdit(posRelGroupBox2);
    drDegLineEdite2 = new QLineEdit(posRelGroupBox2);

    posRelLayout2 = new QFormLayout(posRelGroupBox2);
    posRelLayout2->addRow(tr("实体id"),idLineEdite12);
    posRelLayout2->addRow(tr("相对x坐标"),dxLineEdite2);
    posRelLayout2->addRow(tr("相对y坐标"),dyLineEdite2);
    posRelLayout2->addRow(tr("相对z坐标"),dzLineEdite2);
    posRelLayout2->addRow(tr("相对h角度"),dhDegLineEdite2);
    posRelLayout2->addRow(tr("相对p角度"),dpDegLineEdite2);
    posRelLayout2->addRow(tr("相对r角度"),drDegLineEdite2);

    //2. Animator->FOV
    FOVGroupBox = new QGroupBox(tr("FOV显示"),animatorWidget);
    FOVGroupBox->setCheckable(true);

    showComBox = new QComboBox(FOVGroupBox);
    showComBox->addItems({"0","1"});
    QLineEdit *actorLineEdite6 = new QLineEdit(FOVGroupBox);

    FOVLayout = new QFormLayout(FOVGroupBox);
    FOVLayout->addRow(tr("显示"),showComBox);
    FOVLayout->addRow(tr("id"),actorLineEdite6);

    //animatorWidget布局
    QVBoxLayout *animatorLayout = new QVBoxLayout(animatorWidget);
    animatorLayout->setAlignment(Qt::AlignTop);
    animatorLayout->addWidget(posRelGroupBox2);
    animatorLayout->addWidget(FOVGroupBox);

}

void ScpWidget::init_scpUi()
{
    QVBoxLayout *VLayout = new QVBoxLayout(this);
    scrollArea = new QScrollArea(this);
    stackedWidget = new QStackedWidget(this);
    VLayout->addWidget(scrollArea);

    VLayout->setContentsMargins(0,11,0,11);

    scrollArea->setWidget(stackedWidget);
    scrollArea->setWidgetResizable(true);

    initTrafficWidget();
    initPlayerWidget();
    initEnvactWidget();
    initTrafficlightWidget();
    initSetWidget();
    initAnimatorWidget();

}
