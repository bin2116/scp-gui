#ifndef SCPWIDGET_H
#define SCPWIDGET_H

#include <QComboBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QStackedWidget>
#include <QWidget>
#include <QScrollArea>
#include <QDoubleSpinBox>
#include <QRadioButton>


class ScpWidget: public QWidget
{
    Q_OBJECT
public:
    explicit ScpWidget(QWidget *parent = nullptr);

    QScrollArea * scrollArea;
    QStackedWidget *stackedWidget;

    QWidget *trafficWidget;
    QWidget *playerWidget;
    QWidget *envActWidget;
    QWidget *trafficLightWidget;
    QWidget *setWidget;
    QWidget *animatorWidget;

    //Traffic
    //1. traffic->ActionSpeedChange
    QGroupBox *actSpdChgGroupBox;

    QLineEdit *actorLineEdite;
    QLineEdit *targetLineEdite;
    QLineEdit *rateLineEdite;
    QLineEdit *triggerLineEdite;


    QFormLayout *actSpdChgLayout;

    //2. traffic->ActionRelativeSpeedChange
    QGroupBox *actRelSpdChgGroupBox;

    QLineEdit *actorLineEdite2;
    QLineEdit *relativeactorLineEdite;
    QLineEdit *targetLineEdit;
    QLineEdit *ratetLineEdit2;
    QLineEdit *triggerLineEdite2;


    QFormLayout *actRelSpdChgLayout;

    //3. traffic->ActionLaneChange
    QGroupBox *actLaneChgGroupBox;

    QLineEdit *actLineEdite3;
    QLineEdit *timeLineEdit;
    QLineEdit *valueLineEdit;
    QLineEdit *triggerLineEdite3;


    QFormLayout *actLaneChgLayout;

    //4. traffic->ActionLongitudinalDistance
    QGroupBox *actLongiDisGroupBox;

    QLineEdit *actorLineEdit4;
    QLineEdit *relativeactorLineEdit;
    QLineEdit *distanceLineEdit;
    QLineEdit *maxDecLineEdit;
    QLineEdit *maxAccLineEdit;
    QLineEdit *triggerLineEdite4;


    QFormLayout *actLongiDisLayout;

    //5. traffic->ActionLateralDistance
    QGroupBox *actLateralDisGroupBox;

    QLineEdit *actorLineEdit;
    QLineEdit *relativeactorLineEdit5;
    QLineEdit *triggerLineEdite5;


    QFormLayout *actLateralDisLayout;

    //6. traffic->TrafficSwarmAction
    QGroupBox *trafficSwarmActGroupBox;

    QLineEdit *centralActorLineEdit;
    QComboBox *enableCombox;
    QLineEdit *semiMajorAxisLineEdit;
    QLineEdit *semiMinorAxisLineEdit;
    QLineEdit *innerRadiusLineEdit;
    QLineEdit *offsetLineEdit;
    QLineEdit *numberOfVehiclesLineEdit;


    QFormLayout *trafficSwarmActLayout;

    //7. traffic->TrafficSwarmReset
    QGroupBox *trafficSwarmResetGroupBox;

    //8. traffic->Pause
    QGroupBox *pauseGroupBox;

    //9. traffic->Run
    QGroupBox *runGroupBox;

    //10. traffic->ActionAutonomous
    QGroupBox *actAutoGroupBox;

    QLineEdit *actAutoLineEdit;
    QLineEdit *triggerLineEdite6;


    QFormLayout *actAutoLayout;

    //11. traffic->ActionTrajectory
    QGroupBox *actTraGroupBox;

    QLineEdit *actorLineEdit11;
    QLineEdit *desirSpdLineEdit11;
    QLineEdit *trajectoryLineEdit11;
    QLineEdit *triggerLineEdite7;


    QFormLayout *actTraLayout;

    //12.traffic->ActionPath
    QGroupBox *actionPathGroupBox;

    QLineEdit *actorLineEdit12;
    QLineEdit *pathShapeLineEdit;
    QLineEdit *triggerLineEdite8;
    QComboBox *loopComBox;

    QFormLayout *actionPathLayout;

    //Player
//    QGroupBox *idGroupBox;

    //1. Player->Delete
    QGroupBox *deleteGroupBox;
    QLineEdit *idLineEdite1;

    QFormLayout *deleteLayout;
    //2. Player->DriverBehavior
    QGroupBox *driverBehaviorGroupBox;

    QLineEdit *desirFreSpdLineEdite;
    QLineEdit *desirCrosSpdLineEdite;
    QLineEdit *desirAccLineEdite;
    QLineEdit *desirDccLineEdite;
    QLineEdit *driverNameLineEdite;
    QLineEdit *idLineEdite2;

    QFormLayout *driverBehaviorLayout;

    //3. Player->Creat
    QGroupBox *creatGroupBox;

    QComboBox *categoryComBox;
    QLineEdit *modelLineEdite;
    QLineEdit *driverLineEdite;
    QLineEdit *dxLineEdite;
    QLineEdit *dyLineEdite;
    QLineEdit *dzLineEdite;
    QLineEdit *dhDegLineEdite;
    QLineEdit *dpDegLineEdite;
    QLineEdit *drDegLineEdite;
    QLineEdit *idLineEdite3;

    QFormLayout *creatLayout;

    //4. Player->LeftTurnLight
    QGroupBox *leftTurnLightGroupBox;

    QComboBox *stateComBox;
    QComboBox *stateMaskComBox;
    QLineEdit *idLineEdite4;

    QFormLayout *leftTurnLightLayout;

    //5. Player->RightTurnLight
    QGroupBox *rightTurnLightGroupBox;

    QComboBox *stateComBox5;
    QComboBox *stateMaskComBox5;
    QLineEdit *idLineEdite5;

    QFormLayout *rightTurnLightLayout;

    //6. Player->HeadLight
    QGroupBox *headLightGroupBox;

    QComboBox *stateComBox6;
    QComboBox *stateMaskComBox6;
    QLineEdit *idLineEdite6;

    QFormLayout *headLightLayout;

    //7. Player->BrakeLight
    QGroupBox *brakeLightGroupBox;

    QComboBox *stateComBox7;
    QComboBox *stateMaskComBox7;
    QLineEdit *idLineEdite7;

    QFormLayout *brakeLightLayout;
    //8.Player->PositionAbsolute
    QGroupBox *posAbsGroupBox;

    QLineEdit *xLineEdit;
    QLineEdit *yLineEdit;
    QLineEdit *zLineEdit;
    QLineEdit *hDegLineEdit;
    QLineEdit *idLineEdite8;

    QFormLayout *posAbsLayout;

    //9. Player->PositionRelative
    QGroupBox *posRelGroupBox;

    QLineEdit *actorLineEdit9;
    QLineEdit *disLineEdit;
    QLineEdit *laneLineEdit;
    QLineEdit *offsetLineEdit9;
    QLineEdit *dhDegLineEdit9;
    QLineEdit *idLineEdite9;

    QFormLayout *posRelLayout;

    //EnvironmentAction
    //光照
    QGroupBox *lightGroupBox;
    QComboBox *sunTypeComBox;
    QStackedWidget *sunTypeStackWidget;
    QWidget *lightWidget;
    QWidget *timeWidget;

    QDoubleSpinBox *luxBox;
    QDoubleSpinBox *elevationBox;
    QDoubleSpinBox *azimuthBox;

    QDateTimeEdit *dateEdit;
    QDateTimeEdit *timeEdit;
    QRadioButton * timeFlowButton;


    QFormLayout *envLayout;
    QFormLayout *lightLayout;
    QFormLayout *timeLayout;

    //云层
    QGroupBox *cloudStateGroupBox;
    QComboBox *cloudStateComBox;

    QFormLayout *cloudStateLayout;

    //雨雪
    QGroupBox *rain_snow_GroupBox;

    QComboBox *typeComBox;

    QSlider *value_slider;
    QLineEdit *value_edit;
    QLabel *percen_label;

    QFormLayout *rain_snow_layout;

    //雾/尘
    QGroupBox *fog_dust_groupBox;
    QComboBox *typeComBox2;
    QComboBox *rangeComboBox;
    QLineEdit *visualRange;

    QLineEdit *xLineEdit2;
    QLineEdit *yLineEdit2;
    QLineEdit *zLineEdit2;

    QLineEdit *lengthLineEdit;
    QLineEdit *widthLineEdit;
    QLineEdit *heightLineEdit;

    QFormLayout *fog_dust_layout;

    //路面积水
    QGroupBox *water_groupBox;
    QComboBox *type_comboBox;
    QSlider *water_slider;
    QLineEdit *value_edit2;
    QLabel *percen_label2;

    QFormLayout *water_layout;

    //路面摩擦
    QGroupBox *fric_groupBox;
    QLineEdit *fric_comboBox;

    QFormLayout *fric_layout;

    //TrafficLight

    //1.TrafficLight->SetState节点内容。
    QGroupBox *setStateGroupBox;
    QComboBox *stateComBox2; //设置的状态
    QFormLayout *setStateLayout;
    QLineEdit *idLineEdite10; //交通灯的id
    //2.TrafficLight->SetPhase
    QGroupBox *setPhaseGroupBox;
    QComboBox *stateComBox3;
    QLineEdit *durationLineEdite;
    QFormLayout *setPhaseLayout;
    QLineEdit *idLineEdite11; //交通灯的id

    //Set
    //Set->Trigger
    QGroupBox *triggerGroupBox;
    QLineEdit *ownerLineEdite;
    QLineEdit *nameLineEdite;

    //Set->Trigger->Delete
    QGroupBox *deleteGroupBox2;

    //Set->Trigger->PosAbsolute
    QGroupBox *posAbsGroupBox2;
    QLineEdit *xLineEdite3;
    QLineEdit *yLineEdite3;
    QLineEdit *radiusLineEdite3;
    QFormLayout *posAbsLayout2;

    //Set->Trigger->PosRelative
    QGroupBox *posRelGroupBox3;
    QLineEdit *relActLineEdite; //参考实体的id/name
    QLineEdit *disLineEdite2; //几何距离
    QFormLayout *posRelLayout3;

    //Set->Trigger->TTCRelative
    QGroupBox *TTCRelGroupBox;
    QLineEdit *relActLineEdite2; //参考实体的id/name
    QLineEdit *timeLineEdite2; //距离碰撞的时间
    QFormLayout *TTCRelLayout;

    //Set->Trigger->THRelative
    QGroupBox *THRelGroupBox;
    QLineEdit *relActLineEdite3; //参考实体的id/name
    QLineEdit *timeLineEdite3; //车头时距
    QFormLayout *THRelLayout;

    //Set->Trigger->Speed
    QGroupBox *spdGroupBox;
    QLineEdit *valueLineEdite2; //速度触发的值
    QComboBox * valueCheckBox; //true:超过该值时触发;\nfalse:小于该值时触发
    QFormLayout *spdLayout;
    QVBoxLayout *setPageLayout;
    QVBoxLayout *triggerLayout;

    //Animator
    //1. Animator->PosistionRelative
    QGroupBox *posRelGroupBox2;
    QLineEdit *idLineEdite12; //实体的id
    QLineEdit *dxLineEdite2; //相对本车的x坐标
    QLineEdit *dyLineEdite2; //相对本车的y坐标
    QLineEdit *dzLineEdite2; //相对本车的z坐标
    QLineEdit *dhDegLineEdite2; //相对本车的h角度
    QLineEdit *dpDegLineEdite2; //相对本车的p角度
    QLineEdit *drDegLineEdite2; //相对本车的r角度
    QFormLayout *posRelLayout2;

    //2. Animator->FOV
    QGroupBox *FOVGroupBox;
    QComboBox *showComBox;
    QLineEdit *actorLineEdite6;
    QFormLayout *FOVLayout;
    QVBoxLayout *animatorLayout;

    void init_scpUi();

    void initTrafficWidget();
    void initPlayerWidget();
    void initEnvactWidget();
    void initTrafficlightWidget();
    void initSetWidget();
    void initAnimatorWidget();

signals:

public slots:
};

#endif // SCPWIDGET_H
