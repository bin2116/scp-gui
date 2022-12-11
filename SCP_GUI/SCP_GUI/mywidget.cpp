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
    resize(400,600);

    QComboBox * scp_combox = new QComboBox(this);
    scp_combox->addItems({"Traffic", "Player", "EnvironmentAction", "TrafficLight", "Set", "Animator"});

    QStackedWidget * stackedWidget = new QStackedWidget(this);

    QWidget *trafficPageWidget = new QWidget(stackedWidget);
    QWidget *playerPageWidget = new QWidget(stackedWidget);
    QWidget *environmentAction = new QWidget(stackedWidget);
    QWidget *trafficLightPageWidget = new QWidget(stackedWidget);
    QWidget *setPageWidget = new QWidget(stackedWidget);
    QWidget *animatorPageWidget = new QWidget(stackedWidget);

    stackedWidget->addWidget(trafficPageWidget);
    stackedWidget->addWidget(playerPageWidget);
    stackedWidget->addWidget(environmentAction);
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
    QLineEdit *enableLineEdit = new QLineEdit();

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
    trafficSwarmActGridLayout->addWidget(enableLineEdit,1,1,1,1);

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
    QLineEdit *loopLineEdit = new QLineEdit();

    QGridLayout *actionPathGridLayout = new QGridLayout();

    actionPathGridLayout->addWidget(actorLabel12,0,0,1,1);
    actionPathGridLayout->addWidget(actorLineEdit12,0,1,1,1);

    actionPathGridLayout->addWidget(pathShapeLabel,1,0,1,1);
    actionPathGridLayout->addWidget(pathShapeLineEdit,1,1,1,1);

    actionPathGridLayout->addWidget(loopLabel,2,0,1,1);
    actionPathGridLayout->addWidget(loopLineEdit,2,1,1,1);

    actionPathGroupBox->setLayout(actionPathGridLayout);

    QVBoxLayout *layout2 = new QVBoxLayout(trafficPageWidget);

    layout2->addWidget(actSpdChgGroupBox);
    layout2->addWidget(actRelSpdChgGroupBox);
    layout2->addWidget(actLaneChgGroupBox);
    layout2->addWidget(actLongiDisGroupBox);
    layout2->addWidget(actLateralDisGroupBox);
    layout2->addWidget(trafficSwarmActGroupBox);
    layout2->addWidget(trafficSwarmResetGroupBox);
    layout2->addWidget(pauseGroupBox);
    layout2->addWidget(runGroupBox);
    layout2->addWidget(actAutoGroupBox);
    layout2->addWidget(actTraGroupBox);
    layout2->addWidget(actionPathGroupBox);

//    1. Player->Delete节点内容。
    QGroupBox *deleteGroupBox = new QGroupBox( tr("删除实体(只能删除交通车)"),playerPageWidget);
    deleteGroupBox->setCheckable(true);

//    2. Player->DriverBehavior节点内容。
    QGroupBox *idGroupBox = new QGroupBox( tr("修改实体的驾驶员模型(车辆才能生效)"),playerPageWidget);

    QLabel *idLabel = new QLabel(tr("实体的id"), this);
    QLineEdit *idLineEdite = new QLineEdit(this);

    QGridLayout *idGridLayout = new QGridLayout();
    idGridLayout->addWidget(idLabel,0,0);
    idGridLayout->addWidget(idLineEdite,0,1);

    idGroupBox->setLayout(idGridLayout);



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
    QLineEdit *categoryLineEdite = new QLineEdit(this);

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
    creatGridLayout->addWidget(categoryLineEdite,0,1);

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







}

MyWidget::~MyWidget()
{
    delete ui;
}

