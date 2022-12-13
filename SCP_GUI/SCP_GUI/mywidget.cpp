#include "mywidget.h"
#include "ui_mywidget.h"

#include <QCheckBox>
#include <QComboBox>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QScrollArea>
#include <QStackedWidget>
#include <QVBoxLayout>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
//    resize(500,600);
    QComboBox * scp_combox = new QComboBox(this);
    scp_combox->addItems({"Traffic", "Player", "EnvironmentAction", "TrafficLight", "Set", "Animator"});

    QStackedWidget * stackedWidget = new QStackedWidget(this);

    QWidget *trafficPageWidget = new QWidget(stackedWidget);
    QWidget *playerPageWidget = new QWidget(stackedWidget);
    QWidget *environmentActionPageWidget = new QWidget(stackedWidget);
    QWidget *trafficLightPageWidget = new QWidget(stackedWidget);
    QWidget *setPageWidget = new QWidget(stackedWidget);
    QWidget *animatorPageWidget = new QWidget(stackedWidget);
    stackedWidget->addWidget(trafficPageWidget);
    stackedWidget->addWidget(playerPageWidget);
    stackedWidget->addWidget(environmentActionPageWidget);
    stackedWidget->addWidget(trafficLightPageWidget);
    stackedWidget->addWidget(setPageWidget);
    stackedWidget->addWidget(animatorPageWidget);

    connect(scp_combox, SIGNAL(activated(int)),
            stackedWidget, SLOT(setCurrentIndex(int)));

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(scp_combox);

    QScrollArea * scrollArea = new QScrollArea(this);
    scrollArea->setWidget(stackedWidget);
    scrollArea->setWidgetResizable(true);

    scrollArea->setWidgetResizable(true);
    layout->addWidget(scrollArea);

//        1. traffic->ActionSpeedChange节点内容
    QGroupBox *actSpdChgGroupBox = new QGroupBox( tr("变速"),trafficPageWidget);
    actSpdChgGroupBox->setCheckable(true);

    QLineEdit *actorLineEdite = new QLineEdit(this);
    QLabel *actorLabel = new QLabel(tr("实体id"),this);

    QLineEdit *targetLineEdite = new QLineEdit(this);
    QLabel *targetLabel = new QLabel(tr("目标速度"),this);

    QLineEdit *rateLineEdite = new QLineEdit(this);
    QLabel *rateLabel = new QLabel(tr("最大加速度"));

    QGridLayout *actSpdChgGridLayout = new QGridLayout();

    actSpdChgGridLayout->addWidget(actorLabel,0,0,1,1);
    actSpdChgGridLayout->addWidget(actorLineEdite,0,1,1,1);

    actSpdChgGridLayout->addWidget(targetLabel,1,0,1,1);
    actSpdChgGridLayout->addWidget(targetLineEdite,1,1,1,1);

    actSpdChgGridLayout->addWidget(rateLabel,2,0,1,1);
    actSpdChgGridLayout->addWidget(rateLineEdite,2,1,1,1);

    actSpdChgGroupBox->setLayout(actSpdChgGridLayout);

//     2. traffic->ActionRelativeSpeedChange节点内容
    QGroupBox *actRelSpdChgGroupBox = new QGroupBox(tr("相对变速"),trafficPageWidget);
    actRelSpdChgGroupBox->setCheckable(true);

    QLineEdit *actorLineEdite2 = new QLineEdit(this);
    QLabel *actorLabel2 = new QLabel(tr("实体id"), this);

    QLineEdit *relativeactorLineEdite = new QLineEdit(this);
    QLabel *relativeactorLabel = new QLabel(tr("相对实体id"), this);

    QLineEdit *targetLineEdit = new QLineEdit(this);
    QLabel *targetLabel2 = new QLabel(tr("相对目标的速度"), this);

    QLineEdit *ratetLineEdit2 = new QLineEdit(this);
    QLabel *rateLabel2 = new QLabel(tr("加速度"), this);

    QGridLayout *actRelSpdChgGridLayout = new QGridLayout();

    actRelSpdChgGridLayout->addWidget(actorLabel2,0,0,1,1);
    actRelSpdChgGridLayout->addWidget(actorLineEdite2,0,1,1,1);

    actRelSpdChgGridLayout->addWidget(relativeactorLabel,1,0,1,1);
    actRelSpdChgGridLayout->addWidget(relativeactorLineEdite,1,1,1,1);

    actRelSpdChgGridLayout->addWidget(targetLabel2,2,0,1,1);
    actRelSpdChgGridLayout->addWidget(targetLineEdit,2,1,1,1);

    actRelSpdChgGridLayout->addWidget(rateLabel2,3,0,1,1);
    actRelSpdChgGridLayout->addWidget(ratetLineEdit2,3,1,1,1);

    actRelSpdChgGroupBox->setLayout(actRelSpdChgGridLayout);

//        3. traffic->ActionLaneChange节点内容
    QGroupBox *actLaneChgGroupBox = new QGroupBox(tr("变道"),trafficPageWidget);
    actLaneChgGroupBox->setCheckable(true);

    QLineEdit *actLineEdite3 = new QLineEdit(this);
    QLabel *actorLabel3 = new QLabel(tr("实体id"), this);

    QLabel *timeLabel = new QLabel(tr("变道时间"));
    QLineEdit *timeLineEdit = new QLineEdit();

    QLabel *valueLabel = new QLabel(tr("变道数+(左换道)-(右换道)"));
    QLineEdit *valueLineEdit = new QLineEdit();

    QGridLayout * actLaneChgGridLayout = new QGridLayout(this);

    actLaneChgGridLayout->addWidget(actorLabel3,0,0,1,1);
    actLaneChgGridLayout->addWidget(actLineEdite3,0,1,1,1);

    actLaneChgGridLayout->addWidget(timeLabel,1,0,1,1);
    actLaneChgGridLayout->addWidget(timeLineEdit,1,1,1,1);

    actLaneChgGridLayout->addWidget(valueLabel,2,0,1,1);
    actLaneChgGridLayout->addWidget(valueLineEdit,2,1,1,1);

    actLaneChgGroupBox->setLayout(actLaneChgGridLayout);

//    4. traffic->ActionLongitudinalDistance节点内容
    QGroupBox *actLongiDisGroupBox = new QGroupBox(tr("纵向追车"),trafficPageWidget);
    actLongiDisGroupBox->setCheckable(true);

    QLabel *actorLabel4 = new QLabel(tr("实体id"));
    QLineEdit *actorLineEdit4 = new QLineEdit();

    QLabel *relativeactorLabel4 = new QLabel(tr("相对实体id"));
    QLineEdit *relativeactorLineEdit = new QLineEdit();

    QLabel *distanceLabel = new QLabel(tr("纵向追车距离"));
    QLineEdit *distanceLineEdit = new QLineEdit();

    QLabel *maxDecLabel = new QLabel(tr("最大减速度"));
    QLineEdit *maxDecLineEdit = new QLineEdit();

    QLabel *maxAccLabel = new QLabel(tr("最大加速度"));
    QLineEdit *maxAccLineEdit = new QLineEdit();

    QGridLayout *actLongiDisGridLayout = new QGridLayout();

    actLongiDisGridLayout->addWidget(actorLabel4,0,0,1,1);
    actLongiDisGridLayout->addWidget(actorLineEdit4,0,1,1,1);

    actLongiDisGridLayout->addWidget(relativeactorLabel4,1,0,1,1);
    actLongiDisGridLayout->addWidget(relativeactorLineEdit,1,1,1,1);

    actLongiDisGridLayout->addWidget(distanceLabel,2,0,1,1);
    actLongiDisGridLayout->addWidget(distanceLineEdit,2,1,1,1);

    actLongiDisGridLayout->addWidget(maxDecLabel,3,0,1,1);
    actLongiDisGridLayout->addWidget(maxDecLineEdit,3,1,1,1);

    actLongiDisGridLayout->addWidget(maxAccLabel,4,0,1,1);
    actLongiDisGridLayout->addWidget(maxAccLineEdit,4,1,1,1);

    actLongiDisGroupBox->setLayout(actLongiDisGridLayout);

//    5. traffic->ActionLateralDistance节点内容
    QGroupBox *actLateralDisGroupBox = new QGroupBox(tr("横向追车"),trafficPageWidget);
    actLateralDisGroupBox->setCheckable(true);

    QLabel *actorLabel5 = new QLabel(tr("实体id"));
    QLineEdit *actorLineEdit = new QLineEdit();

    QLabel *relativeactorLabel5 = new QLabel(tr("相对实体id"));
    QLineEdit *relativeactorLineEdit5 = new QLineEdit();

    QGridLayout *actLateralDisGridLayout = new QGridLayout();

    actLateralDisGridLayout->addWidget(actorLabel5,0,0,1,1);
    actLateralDisGridLayout->addWidget(actorLineEdit,0,1,1,1);

    actLateralDisGridLayout->addWidget(relativeactorLabel5,1,0,1,1);
    actLateralDisGridLayout->addWidget(relativeactorLineEdit5,1,1,1,1);

    actLateralDisGroupBox->setLayout(actLateralDisGridLayout);

//    6. traffic->TrafficSwarmAction节点内容
    QGroupBox *trafficSwarmActGroupBox = new QGroupBox(tr("随机交通"),trafficPageWidget);
    trafficSwarmActGroupBox->setCheckable(true);

    QLabel *centralActorLabel = new QLabel(tr("中心实体的id"));
    QLineEdit *centralActorLineEdit = new QLineEdit();

    QLabel *enableLabel = new QLabel(tr("是否开启随机交通"));
//    QLineEdit *enableLineEdit = new QLineEdit();
    QComboBox *enableCombox = new QComboBox();
    enableCombox->addItems({"false","true"});


    QLabel *semiMajorAxisLabel = new QLabel(tr("长轴半径"));
    QLineEdit *semiMajorAxisLineEdit = new QLineEdit();

    QLabel *semiMinorAxisLabel = new QLabel(tr("短轴半径"));
    QLineEdit *semiMinorAxisLineEdit = new QLineEdit();

    QLabel *innerRadiusLabel = new QLabel(tr("内半径"));
    QLineEdit *innerRadiusLineEdit = new QLineEdit();

    QLabel *offsetLabel = new QLabel(tr("中心偏移"));
    QLineEdit *offsetLineEdit = new QLineEdit();

    QLabel *numberOfVehiclesLabel = new QLabel(tr("最大车辆数"));
    QLineEdit *numberOfVehiclesLineEdit = new QLineEdit();

    QGridLayout *trafficSwarmActGridLayout = new QGridLayout();

    trafficSwarmActGridLayout->addWidget(centralActorLabel,0,0,1,1);
    trafficSwarmActGridLayout->addWidget(centralActorLineEdit,0,1,1,1);

    trafficSwarmActGridLayout->addWidget(enableLabel,1,0,1,1);
    trafficSwarmActGridLayout->addWidget(enableCombox,1,1,1,1);

    trafficSwarmActGridLayout->addWidget(semiMajorAxisLabel,2,0,1,1);
    trafficSwarmActGridLayout->addWidget(semiMajorAxisLineEdit,2,1,1,1);

    trafficSwarmActGridLayout->addWidget(semiMinorAxisLabel,3,0,1,1);
    trafficSwarmActGridLayout->addWidget(semiMinorAxisLineEdit,3,1,1,1);

    trafficSwarmActGridLayout->addWidget(innerRadiusLabel,4,0,1,1);
    trafficSwarmActGridLayout->addWidget(innerRadiusLineEdit,4,1,1,1);

    trafficSwarmActGridLayout->addWidget(offsetLabel,5,0,1,1);
    trafficSwarmActGridLayout->addWidget(offsetLineEdit,5,1,1,1);

    trafficSwarmActGridLayout->addWidget(numberOfVehiclesLabel,6,0,1,1);
    trafficSwarmActGridLayout->addWidget(numberOfVehiclesLineEdit,6,1,1,1);

    trafficSwarmActGroupBox->setLayout(trafficSwarmActGridLayout);

//    7. traffic->TrafficSwarmReset节点内容
    QGroupBox *trafficSwarmResetGroupBox = new QGroupBox(tr("重置随机交通"),trafficPageWidget);
    trafficSwarmResetGroupBox->setCheckable(true);

//    8. traffic->Pause节点内容
    QGroupBox *pauseGroupBox = new QGroupBox(tr("交通流停止更新"),trafficPageWidget);
    pauseGroupBox->setCheckable(true);

//    9. traffic->Run节点内容
    QGroupBox *runGroupBox = new QGroupBox(tr("交通流开始更新"),trafficPageWidget);
    runGroupBox->setCheckable(true);

//    10. traffic->ActionAutonomous节点内容
    QGroupBox *actAutoGroupBox = new QGroupBox(tr("激活实体的自动驾驶模式"),trafficPageWidget);
    actAutoGroupBox->setCheckable(true);

    QLabel *actAutoLabel = new QLabel(tr("实体id"));
    QLineEdit *actAutoLineEdit = new QLineEdit();

    QGridLayout *actAutoGridLayout = new QGridLayout();

    actAutoGridLayout->addWidget(actAutoLabel,0,0,1,1);
    actAutoGridLayout->addWidget(actAutoLineEdit,0,1,1,1);

    actAutoGroupBox->setLayout(actAutoGridLayout);

//    11. traffic->ActionTrajectory节点内容
    QGroupBox *actTraGroupBox = new QGroupBox(tr("激活轨迹模式"),trafficPageWidget);
    actTraGroupBox->setCheckable(true);

    QLabel *actorLabel11 = new QLabel(tr("实体id"));
    QLineEdit *actorLineEdit11 = new QLineEdit();

    QLabel *desirSpdLabel = new QLabel(tr("沿轨迹行驶的速度(默认5)"));
    QLineEdit *desirSpdLineEdit11 = new QLineEdit();

    QLabel *trajectoryLabel = new QLabel(tr("库中轨迹的名称"));
    QLineEdit *trajectoryLineEdit11 = new QLineEdit();

    QGridLayout *actTraGridLayout = new QGridLayout();

    actTraGridLayout->addWidget(actorLabel11,0,0,1,1);
    actTraGridLayout->addWidget(actorLineEdit11,0,1,1,1);

    actTraGridLayout->addWidget(desirSpdLabel,1,0,1,1);
    actTraGridLayout->addWidget(desirSpdLineEdit11,1,1,1,1);

    actTraGridLayout->addWidget(trajectoryLabel,2,0,1,1);
    actTraGridLayout->addWidget(trajectoryLineEdit11,2,1,1,1);

    actTraGroupBox->setLayout(actTraGridLayout);

//    12. traffic->ActionPath节点内容
    QGroupBox *actionPathGroupBox = new QGroupBox(tr("设置自动驾驶模式行驶路线"),trafficPageWidget);
    actionPathGroupBox->setCheckable(true);

    QLabel *actorLabel12 = new QLabel(tr("实体id"));
    QLineEdit *actorLineEdit12 = new QLineEdit();

    QLabel *pathShapeLabel = new QLabel(tr("库中行驶路线的名称"));
    QLineEdit *pathShapeLineEdit = new QLineEdit();

    QLabel *loopLabel = new QLabel(tr("沿路线循环行驶"));
//    QLineEdit *loopLineEdit = new QLineEdit();
    QComboBox *loopComBox = new QComboBox(this);
    loopComBox->addItems({"false","true"});


    QGridLayout *actionPathGridLayout = new QGridLayout();

    actionPathGridLayout->addWidget(actorLabel12,0,0,1,1);
    actionPathGridLayout->addWidget(actorLineEdit12,0,1,1,1);

    actionPathGridLayout->addWidget(pathShapeLabel,1,0,1,1);
    actionPathGridLayout->addWidget(pathShapeLineEdit,1,1,1,1);

    actionPathGridLayout->addWidget(loopLabel,2,0,1,1);
    actionPathGridLayout->addWidget(loopComBox,2,1,1,1);

    actionPathGroupBox->setLayout(actionPathGridLayout);

    QVBoxLayout *trafficlayout = new QVBoxLayout(trafficPageWidget);
//    layout2->setSizeConstraint(QLayout::SetFixedSize);
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

    //Player
    QGroupBox *idGroupBox = new QGroupBox(playerPageWidget);
    idGroupBox->setStyleSheet("QGroupBox{border:none}");

    QLabel *idLabel = new QLabel(tr("实体的id"), this);
    QLineEdit *idLineEdite = new QLineEdit(this);

    QGridLayout *idGridLayout = new QGridLayout();
    idGridLayout->addWidget(idLabel,0,0);
    idGridLayout->addWidget(idLineEdite,0,1);

    idGroupBox->setLayout(idGridLayout);
//    1. Player->Delete节点内容。
    QGroupBox *deleteGroupBox = new QGroupBox( tr("删除实体(只能删除交通车)"),playerPageWidget);
    deleteGroupBox->setCheckable(true);

//    2. Player->DriverBehavior节点内容。
    QGroupBox *driverBehaviorGroupBox = new QGroupBox( tr("修改实体的驾驶员模型(车辆才能生效)"),playerPageWidget);
    driverBehaviorGroupBox->setCheckable(true);

    QLabel *desirFreSpdLabel = new QLabel(tr("自由行使期望速度"), this);
    QLineEdit *desirFreSpdLineEdite = new QLineEdit(this);

    QLabel *desirCrosSpdLabel = new QLabel(tr("通过路口期望速度"), this);
    QLineEdit *desirCrosSpdLineEdite = new QLineEdit(this);

    QLabel *desirAccLabel = new QLabel(tr("舒适加速度"), this);
    QLineEdit *desirAccLineEdite = new QLineEdit(this);

    QLabel *desirDccLabel = new QLabel(tr("舒适减速度"), this);
    QLineEdit *desirDccLineEdite = new QLineEdit(this);

    QLabel *driverNameDccLabel = new QLabel(tr("库中驾驶员模型"), this);
    QLineEdit *driverNameLineEdite = new QLineEdit(this);

    QGridLayout *driverBehaviorGridLayout = new QGridLayout(this);

    driverBehaviorGridLayout->addWidget(desirFreSpdLabel,0,0);
    driverBehaviorGridLayout->addWidget(desirFreSpdLineEdite,0,1);

    driverBehaviorGridLayout->addWidget(desirCrosSpdLabel,1,0);
    driverBehaviorGridLayout->addWidget(desirCrosSpdLineEdite,1,1);

    driverBehaviorGridLayout->addWidget(desirAccLabel,2,0);
    driverBehaviorGridLayout->addWidget(desirAccLineEdite,2,1);

    driverBehaviorGridLayout->addWidget(desirDccLabel,3,0);
    driverBehaviorGridLayout->addWidget(desirDccLineEdite,3,1);

    driverBehaviorGridLayout->addWidget(driverNameDccLabel,4,0);
    driverBehaviorGridLayout->addWidget(driverNameLineEdite,4,1);

    driverBehaviorGroupBox->setLayout(driverBehaviorGridLayout);

//    3. Player->Creat节点内容。
    QGroupBox *creatGroupBox = new QGroupBox( tr("创建实体(创建出来的是交通车或行人物体)"),playerPageWidget);
    creatGroupBox->setCheckable(true);

    QLabel *categoryLabel = new QLabel(tr("新建实体的类别"), this);
//    QLineEdit *categoryLineEdite = new QLineEdit(this);
    QComboBox *categoryComBox = new QComboBox(this);
    categoryComBox->addItems({"vehicle","pedestrian","object"});

    QLabel *modelLabel = new QLabel(tr("车辆3D模型名称"), this);
    QLineEdit *modelLineEdite = new QLineEdit(this);

    QLabel *driverLabel = new QLabel(tr("驾驶员模型名称"), this);
    QLineEdit *driverLineEdite = new QLineEdit(this);

    QLabel *dxLabel = new QLabel(tr("相对本车的x坐标"), this);
    QLineEdit *dxLineEdite = new QLineEdit(this);

    QLabel *dyLabel = new QLabel(tr("相对本车的y坐标"), this);
    QLineEdit *dyLineEdite = new QLineEdit(this);

    QLabel *dzLabel = new QLabel(tr("相对本车的z坐标"), this);
    QLineEdit *dzLineEdite = new QLineEdit(this);

    QLabel *dhDegLabel = new QLabel(tr("相对本车的h角度"), this);
    QLineEdit *dhDegLineEdite = new QLineEdit(this);

    QLabel *dpDegLabel = new QLabel(tr("相对本车的p角度"), this);
    QLineEdit *dpDegLineEdite = new QLineEdit(this);

    QLabel *drDegLabel = new QLabel(tr("相对本车的r角度"), this);
    QLineEdit *drDegLineEdite = new QLineEdit(this);

    QGridLayout *creatGridLayout = new QGridLayout();

    creatGridLayout->addWidget(categoryLabel,0,0);
    creatGridLayout->addWidget(categoryComBox,0,1);

    creatGridLayout->addWidget(modelLabel,1,0);
    creatGridLayout->addWidget(modelLineEdite,1,1);

    creatGridLayout->addWidget(driverLabel,2,0);
    creatGridLayout->addWidget(driverLineEdite,2,1);

    creatGridLayout->addWidget(dxLabel,3,0);
    creatGridLayout->addWidget(dxLineEdite,3,1);

    creatGridLayout->addWidget(dyLabel,4,0);
    creatGridLayout->addWidget(dyLineEdite,4,1);

    creatGridLayout->addWidget(dzLabel,5,0);
    creatGridLayout->addWidget(dzLineEdite,5,1);

    creatGridLayout->addWidget(dhDegLabel,6,0);
    creatGridLayout->addWidget(dhDegLineEdite,6,1);

    creatGridLayout->addWidget(dpDegLabel,7,0);
    creatGridLayout->addWidget(dpDegLineEdite,7,1);

    creatGridLayout->addWidget(drDegLabel,8,0);
    creatGridLayout->addWidget(drDegLineEdite,8,1);

    creatGroupBox->setLayout(creatGridLayout);

//    4. Player->LeftTurnLight节点内容。
    QGroupBox *leftTurnLightGroupBox = new QGroupBox(tr("左转向灯"),playerPageWidget);
    leftTurnLightGroupBox->setCheckable(true);

    QLabel *stateLabel = new QLabel(tr("状态"), this);
//    QLineEdit *stateLineEdite = new QLineEdit(this);
    QComboBox *stateComBox = new QComboBox(this);
    stateComBox->addItems({"0","1"});

    QLabel *stateMaskLabel = new QLabel(tr("是否覆盖自动给的转向状态"), this);
//    QLineEdit *stateMaskLineEdite = new QLineEdit(this);
    QComboBox *stateMaskComBox = new QComboBox(this);
    stateMaskComBox->addItems({"0","1"});

    QGridLayout * leftTurnLightGridLayout = new QGridLayout(this);

    leftTurnLightGridLayout->addWidget(stateLabel,0,0);
    leftTurnLightGridLayout->addWidget(stateComBox,0,1);

    leftTurnLightGridLayout->addWidget(stateMaskLabel,1,0);
    leftTurnLightGridLayout->addWidget(stateMaskComBox,1,1);

    leftTurnLightGroupBox->setLayout(leftTurnLightGridLayout);

//    5. Player->RightTurnLight节点内容。
    QGroupBox *rightTurnLightGroupBox = new QGroupBox(tr("右转向灯"),playerPageWidget);
    rightTurnLightGroupBox->setCheckable(true);

    QLabel *stateLabel5 = new QLabel(tr("状态"), this);
//    QLineEdit *stateLineEdite5 = new QLineEdit(this);
    QComboBox *stateComBox5 = new QComboBox(this);
    stateComBox5->addItems({"0","1"});

    QLabel *stateMaskLabel5 = new QLabel(tr("是否覆盖自动给的转向状态"), this);
//    QLineEdit *stateMaskLineEdite5 = new QLineEdit(this);
    QComboBox *stateMaskComBox5 = new QComboBox(this);
    stateMaskComBox5->addItems({"0","1"});

    QGridLayout * rightTurnLightGridLayout = new QGridLayout(this);

    rightTurnLightGridLayout->addWidget(stateLabel5,0,0);
    rightTurnLightGridLayout->addWidget(stateComBox5,0,1);

    rightTurnLightGridLayout->addWidget(stateMaskLabel5,1,0);
    rightTurnLightGridLayout->addWidget(stateMaskComBox5,1,1);

    rightTurnLightGroupBox->setLayout(rightTurnLightGridLayout);

//    6. Player->HeadLight节点内容。
    QGroupBox *headLightGroupBox = new QGroupBox(tr("车头灯"),playerPageWidget);
    headLightGroupBox->setCheckable(true);

    QLabel *stateLabel6 = new QLabel(tr("状态"), this);
//    QLineEdit *stateLineEdite6 = new QLineEdit(this);
    QComboBox *stateComBox6 = new QComboBox(this);
    stateComBox6->addItems({"0","1"});

    QLabel *stateMaskLabel6 = new QLabel(tr("是否覆盖自动给的头灯状态"), this);
//    QLineEdit *stateMaskLineEdite6 = new QLineEdit(this);
    QComboBox *stateMaskComBox6 = new QComboBox(this);
    stateMaskComBox6->addItems({"0","1"});

    QGridLayout * headLightGridLayout = new QGridLayout(this);

    headLightGridLayout->addWidget(stateLabel6,0,0);
    headLightGridLayout->addWidget(stateComBox6,0,1);

    headLightGridLayout->addWidget(stateMaskLabel6,1,0);
    headLightGridLayout->addWidget(stateMaskComBox6,1,1);

    headLightGroupBox->setLayout(headLightGridLayout);

//    7. Player->BrakeLight节点内容。
    QGroupBox *brakeLightGroupBox = new QGroupBox(tr("刹车灯"),playerPageWidget);
    brakeLightGroupBox->setCheckable(true);

    QLabel *stateLabel7 = new QLabel(tr("状态"), this);
//    QLineEdit *stateLineEdite7 = new QLineEdit(this);
    QComboBox *stateComBox7 = new QComboBox(this);
    stateComBox7->addItems({"0","1"});

    QLabel *stateMaskLabel7 = new QLabel(tr("是否覆盖自动给的制动状态"), this);
//    QLineEdit *stateMaskLineEdite7 = new QLineEdit(this);
    QComboBox *stateMaskComBox7 = new QComboBox(this);
    stateMaskComBox7->addItems({"0","1"});

    QGridLayout * brakeLightGridLayout = new QGridLayout(this);

    brakeLightGridLayout->addWidget(stateLabel7,0,0);
    brakeLightGridLayout->addWidget(stateComBox7,0,1);

    brakeLightGridLayout->addWidget(stateMaskLabel7,1,0);
    brakeLightGridLayout->addWidget(stateMaskComBox7,1,1);

    brakeLightGroupBox->setLayout(brakeLightGridLayout);

//     8. Player->PositionAbsolute节点内容。
    QGroupBox *posAbsGroupBox = new QGroupBox(tr("设定交通车的绝对位置"),playerPageWidget);
    posAbsGroupBox->setCheckable(true);

    QLabel *xLabel = new QLabel(tr("x坐标"));
    QLineEdit *xLineEdit = new QLineEdit();

    QLabel *yLabel = new QLabel(tr("y坐标"));
    QLineEdit *yLineEdit = new QLineEdit();

    QLabel *zLabel = new QLabel(tr("z坐标"));
    QLineEdit *zLineEdit = new QLineEdit();

    QLabel *hDegLabel = new QLabel(tr("hDeg坐标"));
    QLineEdit *hDegLineEdit = new QLineEdit();

    QGridLayout *posAbsGridLayout = new QGridLayout();

    posAbsGridLayout->addWidget(xLabel,0,0);
    posAbsGridLayout->addWidget(xLineEdit,0,1);

    posAbsGridLayout->addWidget(yLabel,1,0);
    posAbsGridLayout->addWidget(yLineEdit,1,1);

    posAbsGridLayout->addWidget(zLabel,2,0);
    posAbsGridLayout->addWidget(zLineEdit,2,1);

    posAbsGridLayout->addWidget(hDegLabel,3,0);
    posAbsGridLayout->addWidget(hDegLineEdit,3,1);

    posAbsGroupBox->setLayout(posAbsGridLayout);

//    9. Player->PositionRelative节点内容。
    QGroupBox *posRelGroupBox = new QGroupBox(tr("横向追车"),playerPageWidget);
    posRelGroupBox->setCheckable(true);

    QLabel *actorLabel9 = new QLabel(tr("相对实体id"));
    QLineEdit *actorLineEdit9 = new QLineEdit();

    QLabel *disLabel = new QLabel(tr("相对实体沿道路方向的距离"));
    QLineEdit *disLineEdit = new QLineEdit();

    QLabel *laneLabel = new QLabel(tr("相对实体的车道的id(左+ /右-)"));
    QLineEdit *laneLineEdit = new QLineEdit();

    QLabel *offsetLabel9 = new QLabel(tr("偏离车道的距离(默认为0)"));
    QLineEdit *offsetLineEdit9 = new QLineEdit();

    QLabel *dhDegLabel9 = new QLabel(tr("相对实体的方向角"));
    QLineEdit *dhDegLineEdit9 = new QLineEdit();

    QGridLayout *posRelGridLayout = new QGridLayout();

    posRelGridLayout->addWidget(actorLabel9,0,0);
    posRelGridLayout->addWidget(actorLineEdit9,0,1);

    posRelGridLayout->addWidget(disLabel,1,0);
    posRelGridLayout->addWidget(disLineEdit,1,1);

    posRelGridLayout->addWidget(laneLabel,2,0);
    posRelGridLayout->addWidget(laneLineEdit,2,1);

    posRelGridLayout->addWidget(offsetLabel9,3,0);
    posRelGridLayout->addWidget(offsetLineEdit9,3,1);

    posRelGridLayout->addWidget(dhDegLabel9,4,0);
    posRelGridLayout->addWidget(dhDegLineEdit9,4,1);

    posRelGroupBox->setLayout(posRelGridLayout);

    QVBoxLayout *playerPagelayout = new QVBoxLayout(playerPageWidget);
//    playerPagelayout->setSizeConstraint(QLayout::SetFixedSize);
    playerPagelayout->setAlignment(Qt::AlignTop);

    playerPagelayout->addWidget(idGroupBox);
    playerPagelayout->addWidget(deleteGroupBox);
    playerPagelayout->addWidget(driverBehaviorGroupBox);
    playerPagelayout->addWidget(creatGroupBox);
    playerPagelayout->addWidget(leftTurnLightGroupBox);
    playerPagelayout->addWidget(rightTurnLightGroupBox);
    playerPagelayout->addWidget(headLightGroupBox);
    playerPagelayout->addWidget(brakeLightGroupBox);
    playerPagelayout->addWidget(posAbsGroupBox);
    playerPagelayout->addWidget(posRelGroupBox);



    //EnvironmentAction
//    EnvironmentAction->Environment
    QGroupBox *environmentGroupBox = new QGroupBox("第一层节点环境",environmentActionPageWidget);
    environmentGroupBox->setCheckable(true);

    QGroupBox *sunGroupBox0 = new QGroupBox(environmentGroupBox);
    QLabel *sunTypeLabel0 = new QLabel(tr("太阳类型"));
//    QLineEdit *sunTypeLabelLineEdit = new QLineEdit();
    QComboBox *sunTypeComBox = new QComboBox(this);
    sunTypeComBox->addItems({"sun","time"});

    QGridLayout *sunGridLayout0 = new QGridLayout(sunGroupBox0);

    sunGridLayout0->addWidget(sunTypeLabel0,0,0);
    sunGridLayout0->addWidget(sunTypeComBox,0,1);

    sunGroupBox0->setStyleSheet("QGroupBox{border:none}");



    //    QGridLayout *environmentGridLayout = new QGridLayout(environmentGroupBox);

    //    environmentGridLayout->addWidget(sunTypeLabel,0,0);
    //    environmentGridLayout->addWidget(sunTypeLabelLineEdit,0,1);

//    EnvironmentAction->Environment->TimeOfDay
    QGroupBox *timeOfDayGroupBox = new QGroupBox(tr("交通流开始更新"),environmentGroupBox);
    timeOfDayGroupBox->setCheckable(true);

    QLabel *animationLabel = new QLabel(tr("时间流动"));
//    QLineEdit *animationLineEdit = new QLineEdit();
    QComboBox *animationComBox = new QComboBox(this);
    animationComBox->addItems({"false","true"});

    QLabel *dateTimeLabel = new QLabel(tr("日期时间"));
    QLineEdit *dateTimeLineEdit = new QLineEdit();

    QGridLayout *timeOfDayGridLayout = new QGridLayout(timeOfDayGroupBox);

    timeOfDayGridLayout->addWidget(animationLabel,0,0);
    timeOfDayGridLayout->addWidget(animationComBox,0,1);

    timeOfDayGridLayout->addWidget(dateTimeLabel,1,0);
    timeOfDayGridLayout->addWidget(dateTimeLineEdit,1,1);


//    EnvironmentAction->Environment->Weather
    QGroupBox *weatherGroupBox = new QGroupBox(tr("天气节点"),environmentGroupBox);
    weatherGroupBox->setCheckable(true);

    QGroupBox *cloudStateGroupBox = new QGroupBox(weatherGroupBox);
    QLabel *cloudStateLabel = new QLabel(tr("天空云层类型"));
//    QLineEdit *cloudStateLineEdit = new QLineEdit();
    QComboBox *cloudStateComBox = new QComboBox(this);
    cloudStateComBox->addItems({"skyOff","free","cloudy",
                                "over","cast","rainy"});


    QGridLayout *cloudStateGridLayout = new QGridLayout(cloudStateGroupBox);
    cloudStateGridLayout->addWidget(cloudStateLabel,0,0);
    cloudStateGridLayout->addWidget(cloudStateComBox,0,1);

    cloudStateGroupBox->setStyleSheet("QGroupBox{border:none}");

    //    QGridLayout *weatherGridLayout = new QGridLayout(weatherGroupBox);

    //    weatherGridLayout->addWidget(cloudStateLabel,0,0);
    //    weatherGridLayout->addWidget(cloudStateLineEdit,0,1);

//    EnvironmentAction->Environment->Weather->Sun
    QGroupBox *sunGroupBox = new QGroupBox(tr("太阳类型(只有在suntype=sun时有效)"),weatherGroupBox);
    sunGroupBox->setCheckable(true);

    QLabel *intensityLabel = new QLabel(tr("光强"));
    QLineEdit *intensityLineEdit = new QLineEdit();

    QLabel *elevationLabel = new QLabel(tr("海拔弧度"));
    QLineEdit *elevationLineEdit = new QLineEdit();

    QLabel *azimuthLabel = new QLabel(tr("方向弧度"));
    QLineEdit *azimuthLineEdit = new QLineEdit();

    QGridLayout *sunGridLayout = new QGridLayout(sunGroupBox);

    sunGridLayout->addWidget(intensityLabel,0,0);
    sunGridLayout->addWidget(intensityLineEdit,0,1);

    sunGridLayout->addWidget(elevationLabel,1,0);
    sunGridLayout->addWidget(elevationLineEdit,1,1);

    sunGridLayout->addWidget(azimuthLabel,2,0);
    sunGridLayout->addWidget(azimuthLineEdit,2,1);


 //    EnvironmentAction->Environment->Weather->Fog
    QGroupBox *fogGroupBox = new QGroupBox(tr("雾节点"),weatherGroupBox);
    fogGroupBox->setCheckable(true);

    QGroupBox *typeGroupBox = new QGroupBox(fogGroupBox);
    typeGroupBox->setStyleSheet("QGroupBox{border:none}");
    QLabel *typeLabel = new QLabel(tr("雾类型"));
//    QLineEdit *typeLineEdit = new QLineEdit();
    QComboBox *typeComBox = new QComboBox(this);
    typeComBox->addItems({"fog","dust"});

    QGridLayout *typeGridLayout = new QGridLayout(typeGroupBox);
    typeGridLayout->addWidget(typeLabel,0,0);
    typeGridLayout->addWidget(typeComBox,0,1);

    QGroupBox *fogRangeGroupBox = new QGroupBox(fogGroupBox);
    fogRangeGroupBox->setStyleSheet("QGroupBox{border:none}");
    QLabel *fogRangeLabel = new QLabel(tr("范围"));
//    QLineEdit *fogRangeLineEdit = new QLineEdit();
    QComboBox *fogRangeComBox = new QComboBox(this);
    fogRangeComBox->addItems({"global","local"});

    QGridLayout *fogRangeGridLayout = new QGridLayout(fogRangeGroupBox);
    fogRangeGridLayout->addWidget(fogRangeLabel,0,0);
    fogRangeGridLayout->addWidget(fogRangeComBox,0,1);

    QGroupBox *visualRangeGroupBox = new QGroupBox(fogGroupBox);
    visualRangeGroupBox->setStyleSheet("QGroupBox{border:none}");
    QLabel *visualRangeLabel = new QLabel(tr("可视距离"));
    QLineEdit *visualRangeLineEdit = new QLineEdit();

    QGridLayout *visualRangeGridLayout = new QGridLayout(visualRangeGroupBox);
    visualRangeGridLayout->addWidget(visualRangeLabel,0,0);
    visualRangeGridLayout->addWidget(visualRangeLineEdit,0,1);




    //    QGridLayout *fogGridLayout = new QGridLayout(fogGroupBox);

    //    fogGridLayout->addWidget(typeLabel,0,0);
    //    fogGridLayout->addWidget(typeLineEdit,0,1);

    //    fogGridLayout->addWidget(fogRangeLabel,1,0);
    //    fogGridLayout->addWidget(fogRangeLineEdit,1,1);

    //    fogGridLayout->addWidget(visualRangeLabel,2,0);
    //    fogGridLayout->addWidget(visualRangeLineEdit,2,1);

//    EnvironmentAction->Environment->Weather->Fog->BoundingBox
    QGroupBox *boundingBoxGroupBox = new QGroupBox(tr("局部雾范围节点"),fogGroupBox);
    boundingBoxGroupBox->setCheckable(true);


//    EnvironmentAction->Environment->Weather->Fog->BoundingBox->Center
    QGroupBox *centerGroupBox = new QGroupBox(tr("局部雾中心点"),boundingBoxGroupBox);
    centerGroupBox->setCheckable(true);

    QLabel *xLabel2 = new QLabel(tr("x坐标"));
    QLineEdit *xLineEdit2 = new QLineEdit();

    QLabel *yLabel2 = new QLabel(tr("y坐标"));
    QLineEdit *yLineEdit2 = new QLineEdit();

    QLabel *zLabel2 = new QLabel(tr("z坐标"));
    QLineEdit *zLineEdit2 = new QLineEdit();

    QGridLayout *centerGridLayout = new QGridLayout(centerGroupBox);

    centerGridLayout->addWidget(xLabel2,0,0);
    centerGridLayout->addWidget(xLineEdit2,0,1);

    centerGridLayout->addWidget(yLabel2,1,0);
    centerGridLayout->addWidget(yLineEdit2,1,1);

    centerGridLayout->addWidget(zLabel2,2,0);
    centerGridLayout->addWidget(zLineEdit2,2,1);

//    EnvironmentAction->Environment->Weather->Fog->BoundingBox->Dimensions
    QGroupBox *dimGroupBox = new QGroupBox(tr("局部雾的范围"),boundingBoxGroupBox);
    dimGroupBox->setCheckable(true);

    QLabel *lenLabel = new QLabel(tr("雾框的长度"));
    QLineEdit *lenLineEdit = new QLineEdit();

    QLabel *heightLabel = new QLabel(tr("雾框的高度"));
    QLineEdit *heightLineEdit = new QLineEdit();

    QLabel *widthLabel = new QLabel(tr("雾框的宽度"));
    QLineEdit *widthLineEdit = new QLineEdit();

    QGridLayout *dimGridLayout = new QGridLayout(dimGroupBox);

    dimGridLayout->addWidget(lenLabel,0,0);
    dimGridLayout->addWidget(lenLineEdit,0,1);

    dimGridLayout->addWidget(heightLabel,1,0);
    dimGridLayout->addWidget(heightLineEdit,1,1);

    dimGridLayout->addWidget(widthLabel,2,0);
    dimGridLayout->addWidget(widthLineEdit,2,1);

//    EnvironmentAction->Environment->Weather->Precipitation
    QGroupBox *precGroupBox = new QGroupBox(tr("下雨类型"),weatherGroupBox);
    precGroupBox->setCheckable(true);

    QLabel *intensityLabel2 = new QLabel(tr("强度"));
    QLineEdit *intensityLineEdit2 = new QLineEdit();

    QLabel *precLabel = new QLabel(tr("下雨类型"));
//    QLineEdit *precLineEdit = new QLineEdit();
    QComboBox *precComBox = new QComboBox(this);
    precComBox->addItems({"dry","rain","snow"});

    QGridLayout *precGridLayout = new QGridLayout(precGroupBox);

    precGridLayout->addWidget(intensityLabel2,0,0);
    precGridLayout->addWidget(intensityLineEdit2,0,1);

    precGridLayout->addWidget(precLabel,1,0);
    precGridLayout->addWidget(precComBox,1,1);

//    EnvironmentAction->Environment->RoadCondition
    QGroupBox *roadConGroupBox = new QGroupBox(tr("路面条件"),environmentGroupBox);
    roadConGroupBox->setCheckable(true);

    QLabel *fricScalLabel = new QLabel(tr("摩擦系数"));
    QLineEdit *fricScalLineEdit = new QLineEdit();

    QGridLayout *roadConGridLayout = new QGridLayout(roadConGroupBox);
    roadConGridLayout->addWidget(fricScalLabel,0,0);
    roadConGridLayout->addWidget(fricScalLineEdit,0,1);

//    EnvironmentAction->Environment->Properties
    QGroupBox *propertiesGroupBox = new QGroupBox(tr("其他属性"),environmentGroupBox);
    propertiesGroupBox->setCheckable(true);


//    EnvironmentAction->Environment->Properties->Property1
    QGroupBox *property1GroupBox = new QGroupBox(tr("属性一"),propertiesGroupBox);
    property1GroupBox->setCheckable(true);

    QLabel *name1Label = new QLabel(tr("name1 积水"), this);
    QLineEdit *name1LineEdite = new QLineEdit(this);

    QLabel *value1Label = new QLabel(tr("value1 积水类型"), this);
//    QLineEdit *value1LineEdite = new QLineEdit(this);
    QComboBox *value1ComBox = new QComboBox(this);
    value1ComBox->addItems({"dry","rain","snow"});

    QGridLayout *name1GridLayout = new QGridLayout(property1GroupBox);

    name1GridLayout->addWidget(name1Label,0,0);
    name1GridLayout->addWidget(name1LineEdite,0,1);

    name1GridLayout->addWidget(value1Label,1,0);
    name1GridLayout->addWidget(value1ComBox,1,1);

    //    EnvironmentAction->Environment->Properties->Property2
    QGroupBox *property2GroupBox = new QGroupBox(tr("属性二"),propertiesGroupBox);
    property2GroupBox->setCheckable(true);

    QLabel *name2Label = new QLabel(tr("name2 积水量"), this);
    QLineEdit *name2LineEdite = new QLineEdit(this);

    QLabel *value2Label = new QLabel(tr("value2 积水类型"), this);
    QLineEdit *value2LineEdite = new QLineEdit(this);

    QGridLayout *name2GridLayout = new QGridLayout(property2GroupBox);

    name2GridLayout->addWidget(name2Label,0,0);
    name2GridLayout->addWidget(name2LineEdite,0,1);

    name2GridLayout->addWidget(value2Label,1,0);
    name2GridLayout->addWidget(value2LineEdite,1,1);




    QVBoxLayout *envLayout = new QVBoxLayout(environmentActionPageWidget);
    envLayout->addWidget(environmentGroupBox);
//    envLayout->setSizeConstraint(QLayout::SetFixedSize);
    envLayout->setAlignment(Qt::AlignTop);


    QVBoxLayout *layout3 = new QVBoxLayout(environmentGroupBox);
    layout3->addWidget(sunGroupBox0);
    layout3->addWidget(timeOfDayGroupBox);
    layout3->addWidget(weatherGroupBox);
    layout3->addWidget(roadConGroupBox);
    layout3->addWidget(propertiesGroupBox);

//    envLayout->addWidget(sunGroupBox0);
//    envLayout->addWidget(timeOfDayGroupBox);
//    envLayout->addWidget(weatherGroupBox);
//    envLayout->addWidget(roadConGroupBox);
//    envLayout->addWidget(propertiesGroupBox);

    QVBoxLayout *weatherVLayout = new QVBoxLayout(weatherGroupBox);
    weatherVLayout->addWidget(cloudStateGroupBox);
    weatherVLayout->addWidget(sunGroupBox);
    weatherVLayout->addWidget(fogGroupBox);
    weatherVLayout->addWidget(precGroupBox);

    QVBoxLayout *properVLayout = new QVBoxLayout(propertiesGroupBox);
    properVLayout->addWidget(property1GroupBox);
    properVLayout->addWidget(property2GroupBox);

    QVBoxLayout *fogVLayout = new QVBoxLayout(fogGroupBox);
    fogVLayout->addWidget(typeGroupBox);
    fogVLayout->addWidget(fogRangeGroupBox);
    fogVLayout->addWidget(visualRangeGroupBox);
    fogVLayout->addWidget(boundingBoxGroupBox);

    QVBoxLayout *boundingBoxVLayout = new QVBoxLayout(boundingBoxGroupBox);
    boundingBoxVLayout->addWidget(centerGroupBox);
    boundingBoxVLayout->addWidget(dimGroupBox);



    //TrafficLight
    QGroupBox *idGroupBox2 = new QGroupBox(trafficLightPageWidget);
//    idGroupBox2->setCheckable(true);

    QLabel *idLabel2 = new QLabel(tr("交通灯的id"), this);
    QLineEdit *idLineEdite2 = new QLineEdit(this);

    QGridLayout *idGridLayout2 = new QGridLayout(this);
    idGridLayout2->addWidget(idLabel2,0,0);
    idGridLayout2->addWidget(idLineEdite2,0,1);


    idGroupBox2->setLayout(idGridLayout2);
    idGroupBox2->setStyleSheet("QGroupBox{border:none}");
//    1.TrafficLight->SetState节点内容。
    QGroupBox *setStateGroupBox = new QGroupBox( tr("设置交通灯当前的状态"),trafficLightPageWidget);
    setStateGroupBox->setCheckable(true);

    QLabel *stateLabel2 = new QLabel(tr("设置的状态"), this);
//    QLineEdit *stateLineEdite2 = new QLineEdit(this);
    QComboBox *stateComBox2 = new QComboBox(this);
    stateComBox2->addItems({"stop","go","attention"});

    QGridLayout *setStateGridLayout = new QGridLayout(this);

    setStateGridLayout->addWidget(stateLabel2,0,0);
    setStateGridLayout->addWidget(stateComBox2,0,1);

    setStateGroupBox->setLayout(setStateGridLayout);

//    2.TrafficLight->SetPhase节点内容。
    QGroupBox *setPhaseGroupBox = new QGroupBox( tr("设置交通灯的相位的时长"),trafficLightPageWidget);
    setPhaseGroupBox->setCheckable(true);

    QLabel *stateLabel3 = new QLabel(tr("设置的相位"), this);
//    QLineEdit *stateLineEdite3 = new QLineEdit(this);
    QComboBox *stateComBox3 = new QComboBox(this);
    stateComBox3->addItems({"stop","go","attention"});


    QLabel *durationLabel = new QLabel(tr("设置持续时间"), this);
    QLineEdit *durationLineEdite = new QLineEdit(this);

    QGridLayout *setPhaseGridLayout = new QGridLayout(this);

    setPhaseGridLayout->addWidget(stateLabel3,0,0);
    setPhaseGridLayout->addWidget(stateComBox3,0,1);

    setPhaseGridLayout->addWidget(durationLabel,1,0);
    setPhaseGridLayout->addWidget(durationLineEdite,1,1);

    setPhaseGroupBox->setLayout(setPhaseGridLayout);

    QVBoxLayout *trafficLightLayout = new QVBoxLayout(trafficLightPageWidget);
//    trafficLightLayout->setSizeConstraint(QLayout::SetFixedSize);
    trafficLightLayout->setAlignment(Qt::AlignTop);


    trafficLightLayout->addWidget(idGroupBox2);
    trafficLightLayout->addWidget(setStateGroupBox);
    trafficLightLayout->addWidget(setPhaseGroupBox);

    //Set
    //Set->Trigger
    QGroupBox *triggerGroupBox = new QGroupBox(tr("设置触发节点"),setPageWidget);
    triggerGroupBox->setCheckable(true);

    QGroupBox *ownerGroupBox = new QGroupBox(triggerGroupBox);
    QLabel *ownerLabel = new QLabel(tr("该触发的所有者"));
    QLineEdit *ownerLineEdite = new QLineEdit(this);

    QGridLayout *ownerGridLayout = new QGridLayout(ownerGroupBox);
    ownerGridLayout->addWidget(ownerLabel,0,0);
    ownerGridLayout->addWidget(ownerLineEdite,0,1);

    QGroupBox *nameGroupBox = new QGroupBox(triggerGroupBox);
    QLabel *nameLabel = new QLabel(tr("该触发的名称"));
    QLineEdit *nameLineEdite = new QLineEdit(this);

    QGridLayout *nameGridLayout = new QGridLayout(nameGroupBox);
    nameGridLayout->addWidget(nameLabel,0,0);
    nameGridLayout->addWidget(nameLineEdite,0,1);

//    Set->Trigger->Delete
    QGroupBox *deleteGroupBox2 = new QGroupBox("删除节点",triggerGroupBox);
    deleteGroupBox2->setCheckable(true);

//    Set->Trigger->PosAbsolute
    QGroupBox *posAbsGroupBox2 = new QGroupBox("绝对位置触发",triggerGroupBox);
    posAbsGroupBox2->setCheckable(true);

    QLabel *xLabel3 = new QLabel(tr("触发点的x坐标"));
    QLineEdit *xLineEdite3 = new QLineEdit(this);

    QLabel *yLabel3 = new QLabel(tr("触发点的y坐标"));
    QLineEdit *yLineEdite3 = new QLineEdit(this);

    QLabel *radiusLabel3 = new QLabel(tr("触发点的半径"));
    QLineEdit *radiusLineEdite3 = new QLineEdit(this);

    QGridLayout *posAbsGridLayout2 = new QGridLayout(posAbsGroupBox2);
    posAbsGridLayout2->addWidget(xLabel3,0,0);
    posAbsGridLayout2->addWidget(xLineEdite3,0,1);

    posAbsGridLayout2->addWidget(yLabel3,1,0);
    posAbsGridLayout2->addWidget(yLineEdite3,1,1);

    posAbsGridLayout2->addWidget(radiusLabel3,2,0);
    posAbsGridLayout2->addWidget(radiusLineEdite3,2,1);


//  Set->Trigger->PosRelative
    QGroupBox *posRelGroupBox3 = new QGroupBox("相对位置触发",triggerGroupBox);
    posRelGroupBox3->setCheckable(true);

    QLabel *relActLabel = new QLabel(tr("参考实体的 id/name"));
    QLineEdit *relActLineEdite = new QLineEdit(this);

    QLabel *disLabel2 = new QLabel(tr("几何距离"));
    QLineEdit *disLineEdite2 = new QLineEdit(this);

    QGridLayout *posRelGridLayout3 = new QGridLayout(posRelGroupBox3);
    posRelGridLayout3->addWidget(relActLabel,0,0);
    posRelGridLayout3->addWidget(relActLineEdite,0,1);

    posRelGridLayout3->addWidget(disLabel2,1,0);
    posRelGridLayout3->addWidget(disLineEdite2,1,1);

//  Set->Trigger->TTCRelative
    QGroupBox *TTCRelGroupBox = new QGroupBox("相对碰撞触发",triggerGroupBox);
    TTCRelGroupBox->setCheckable(true);

    QLabel *relActLabel2 = new QLabel(tr("参考实体的 id/name"));
    QLineEdit *relActLineEdite2 = new QLineEdit(this);

    QLabel *timeLabel2 = new QLabel(tr("参考实体的 id/name"));
    QLineEdit *timeLineEdite2 = new QLineEdit(this);

    QGridLayout *TTCRelGridLayout = new QGridLayout(TTCRelGroupBox);
    TTCRelGridLayout->addWidget(relActLabel2,0,0);
    TTCRelGridLayout->addWidget(relActLineEdite2,0,1);

    TTCRelGridLayout->addWidget(timeLabel2,1,0);
    TTCRelGridLayout->addWidget(timeLineEdite2,1,1);

//    Set->Trigger->THRelative
    QGroupBox *THRelGroupBox = new QGroupBox("车头时距触发",triggerGroupBox);
    THRelGroupBox->setCheckable(true);

    QLabel *relActLabel3 = new QLabel(tr("参考实体的 id/name"));
    QLineEdit *relActLineEdite3 = new QLineEdit(this);

    QLabel *timeLabel3 = new QLabel(tr("车头时距"));
    QLineEdit *timeLineEdite3 = new QLineEdit(this);

    QGridLayout *THRelGridLayout = new QGridLayout(THRelGroupBox);
    THRelGridLayout->addWidget(relActLabel3,0,0);
    THRelGridLayout->addWidget(relActLineEdite3,0,1);

    THRelGridLayout->addWidget(timeLabel3,1,0);
    THRelGridLayout->addWidget(timeLineEdite3,1,1);

//    Set->Trigger->Speed
    QGroupBox *spdGroupBox = new QGroupBox("速度触发",triggerGroupBox);
    spdGroupBox->setCheckable(true);

    QLabel *valueLabel2 = new QLabel(tr("速度触发的值"));
    QLineEdit *valueLineEdite2 = new QLineEdit(this);

    QLabel *valueLabel3 = new QLabel(tr("true:超过该值时触发;\nfalse:小于该值时触发"));
    QComboBox * valueCheckBox = new QComboBox(this);
    valueCheckBox->addItems({"true","false"});

    QGridLayout *spdGridLayout = new QGridLayout(spdGroupBox);
    spdGridLayout->addWidget(valueLabel2,0,0);
    spdGridLayout->addWidget(valueLineEdite2,0,1);

    spdGridLayout->addWidget(valueLabel3,1,0);
    spdGridLayout->addWidget(valueCheckBox,1,1);


    QVBoxLayout *setPageLayout = new QVBoxLayout(setPageWidget);
    setPageLayout->addWidget(triggerGroupBox);
//    setPageLayout->setSizeConstraint(QLayout::SetFixedSize);
    setPageLayout->setAlignment(Qt::AlignTop);

    QVBoxLayout *triggerLayout = new QVBoxLayout(triggerGroupBox);
    triggerLayout->addWidget(ownerGroupBox);
    triggerLayout->addWidget(nameGroupBox);
    triggerLayout->addWidget(deleteGroupBox2);
    triggerLayout->addWidget(posAbsGroupBox2);
    triggerLayout->addWidget(posRelGroupBox3);
    triggerLayout->addWidget(TTCRelGroupBox);
    triggerLayout->addWidget(THRelGroupBox);
    triggerLayout->addWidget(spdGroupBox);



    //Animator
    //1. Animator->PosistionRelative
    QGroupBox *posRelGroupBox2 = new QGroupBox( tr("摄像头相对于主车的相对位置"),animatorPageWidget);
    posRelGroupBox2->setCheckable(true);

    QLabel *idLabel3 = new QLabel(tr("实体的id"));
    QLineEdit *idLineEdite3 = new QLineEdit(this);

    QLabel *dxLabel2 = new QLabel(tr("相对本车的x坐标"));
    QLineEdit *dxLineEdite2 = new QLineEdit(this);

    QLabel *dyLabel2 = new QLabel(tr("相对本车的y坐标"));
    QLineEdit *dyLineEdite2 = new QLineEdit(this);

    QLabel *dzLabel2 = new QLabel(tr("相对本车的z坐标"));
    QLineEdit *dzLineEdite2 = new QLineEdit(this);

    QLabel *dhDegLabel2 = new QLabel(tr("相对本车的h角度"));
    QLineEdit *dhDegLineEdite2 = new QLineEdit(this);

    QLabel *dpDegLabel2 = new QLabel(tr("相对本车的p角度"));
    QLineEdit *dpDegLineEdite2 = new QLineEdit(this);

    QLabel *drDegLabel2 = new QLabel(tr("相对本车的r角度"));
    QLineEdit *drDegLineEdite2 = new QLineEdit(this);

    QGridLayout *posRelGridLayout2 = new QGridLayout();

    posRelGridLayout2->addWidget(idLabel3,0,0);
    posRelGridLayout2->addWidget(idLineEdite3,0,1);

    posRelGridLayout2->addWidget(dxLabel2,1,0);
    posRelGridLayout2->addWidget(dxLineEdite2,1,1);

    posRelGridLayout2->addWidget(dyLabel2,2,0);
    posRelGridLayout2->addWidget(dyLineEdite2,2,1);

    posRelGridLayout2->addWidget(dzLabel2,3,0);
    posRelGridLayout2->addWidget(dzLineEdite2,3,1);

    posRelGridLayout2->addWidget(dhDegLabel2,4,0);
    posRelGridLayout2->addWidget(dhDegLineEdite2,4,1);

    posRelGridLayout2->addWidget(dpDegLabel2,5,0);
    posRelGridLayout2->addWidget(dpDegLineEdite2,5,1);

    posRelGridLayout2->addWidget(drDegLabel2,6,0);
    posRelGridLayout2->addWidget(drDegLineEdite2,6,1);

    posRelGroupBox2->setLayout(posRelGridLayout2);

    //2. Animator->FOV
    QGroupBox *FOVGroupBox = new QGroupBox(tr("FOV显示"),animatorPageWidget);
    FOVGroupBox->setCheckable(true);

    QLabel *showLabel = new QLabel(tr("显示"), this);
    QComboBox *showComBox = new QComboBox(this);
    showComBox->addItems({"0","1"});
//    QLineEdit *showLineEdite = new QLineEdit(this);

    QLabel *actorLabel6 = new QLabel(tr("id"), this);
    QLineEdit *actorLineEdite6 = new QLineEdit(this);

    QGridLayout *FOVGridLayout = new QGridLayout(this);
    FOVGridLayout->addWidget(showLabel,0,0);
    FOVGridLayout->addWidget(showComBox,0,1);
//    FOVGridLayout->addWidget(showLineEdite,0,1);

    FOVGridLayout->addWidget(actorLabel6,1,0);
    FOVGridLayout->addWidget(actorLineEdite6,1,1);

    FOVGroupBox->setLayout(FOVGridLayout);


    QVBoxLayout *animatorLayout = new QVBoxLayout(animatorPageWidget);
//    animatorLayout->setSizeConstraint(QLayout::SetFixedSize);
    animatorLayout->setAlignment(Qt::AlignTop);
    animatorLayout->addWidget(posRelGroupBox2);
    animatorLayout->addWidget(FOVGroupBox);

    this->adjustSize();

}

MyWidget::~MyWidget()
{
    delete ui;
}

