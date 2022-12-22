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

    QFormLayout *actSpdChgLayout;

    //2. traffic->ActionRelativeSpeedChange
    QGroupBox *actRelSpdChgGroupBox;

    QLineEdit *actorLineEdite2;
    QLineEdit *relativeactorLineEdite;
    QLineEdit *targetLineEdit;
    QLineEdit *ratetLineEdit2;

    QFormLayout *actRelSpdChgLayout;

    //3. traffic->ActionLaneChange
    QGroupBox *actLaneChgGroupBox;

    QLineEdit *actLineEdite3;
    QLineEdit *timeLineEdit;
    QLineEdit *valueLineEdit;

    QFormLayout *actLaneChgLayout;

    //4. traffic->ActionLongitudinalDistance
    QGroupBox *actLongiDisGroupBox;

    QLineEdit *actorLineEdit4;
    QLineEdit *relativeactorLineEdit;
    QLineEdit *distanceLineEdit;
    QLineEdit *maxDecLineEdit;
    QLineEdit *maxAccLineEdit;

    QFormLayout *actLongiDisLayout;

    //5. traffic->ActionLateralDistance
    QGroupBox *actLateralDisGroupBox;

    QLineEdit *actorLineEdit;
    QLineEdit *relativeactorLineEdit5;

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

    QFormLayout *actAutoLayout;

    //11. traffic->ActionTrajectory
    QGroupBox *actTraGroupBox;

    QLineEdit *actorLineEdit11;
    QLineEdit *desirSpdLineEdit11;
    QLineEdit *trajectoryLineEdit11;

    QFormLayout *actTraLayout;

    //12.traffic->ActionPath
    QGroupBox *actionPathGroupBox;

    QLineEdit *actorLineEdit12;
    QLineEdit *pathShapeLineEdit;
    QComboBox *loopComBox;

    QFormLayout *actionPathLayout;

    QVBoxLayout *trafficlayout;

    //Player
//    QGroupBox *idGroupBox;

    QLineEdit *idLineEdite;

    QFormLayout *idLayout;

    //1. Player->Delete
    QGroupBox *deleteGroupBox;

    //2. Player->DriverBehavior
    QGroupBox *driverBehaviorGroupBox;

    QLineEdit *desirFreSpdLineEdite;
    QLineEdit *desirCrosSpdLineEdite;
    QLineEdit *desirAccLineEdite;
    QLineEdit *desirDccLineEdite;
    QLineEdit *driverNameLineEdite;

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

    QFormLayout *creatLayout;

    //4. Player->LeftTurnLight
    QGroupBox *leftTurnLightGroupBox;

    QComboBox *stateComBox;
    QComboBox *stateMaskComBox;

    QFormLayout *leftTurnLightLayout;

    //5. Player->RightTurnLight
    QGroupBox *rightTurnLightGroupBox;

    QComboBox *stateComBox5;
    QComboBox *stateMaskComBox5;

    QFormLayout *rightTurnLightLayout;

    //6. Player->HeadLight
    QGroupBox *headLightGroupBox;

    QComboBox *stateComBox6;
    QComboBox *stateMaskComBox6;

    QFormLayout *headLightLayout;

    //7. Player->BrakeLight
    QGroupBox *brakeLightGroupBox;

    QComboBox *stateComBox7;
    QComboBox *stateMaskComBox7;



    //8.Player->PositionAbsolute
    QGroupBox *posAbsGroupBox;

    QLineEdit *xLineEdit;
    QLineEdit *yLineEdit;
    QLineEdit *zLineEdit;
    QLineEdit *hDegLineEdit;

    QFormLayout *posAbsLayout;

    //9. Player->PositionRelative
    QGroupBox *posRelGroupBox;

    QLineEdit *actorLineEdit9;
    QLineEdit *disLineEdit;
    QLineEdit *laneLineEdit;
    QLineEdit *offsetLineEdit9;
    QLineEdit *dhDegLineEdit9;

    QFormLayout *posRelLayout;

    QVBoxLayout *playerPagelayout;
    //EnvironmentAction
    //EnvironmentAction->Environment
    QGroupBox *environmentGroupBox;

    QComboBox *sunTypeComBox;

   //EnvironmentAction->Environment->TimeOfDay
    QGroupBox *timeOfDayGroupBox;

    QComboBox *animationComBox;
    QLineEdit *dateTimeLineEdit;

    QFormLayout *timeOfDayLayout;

    //EnvironmentAction->Environment->Weather
    QGroupBox *weatherGroupBox;

    QComboBox *cloudStateComBox;

    QFormLayout *cloudStateLayout;

    //EnvironmentAction->Environment->Weather->Sun
    QGroupBox *sunGroupBox;

    QLineEdit *intensityLineEdit;
    QLineEdit *elevationLineEdit;
    QLineEdit *azimuthLineEdit;

    QFormLayout *sunLayout;

    //EnvironmentAction->Environment->Weather->Fog
    QGroupBox *fogGroupBox;

    QComboBox *typeComBox;
    QComboBox *fogRangeComBox;
    QLineEdit *visualRangeLineEdit;

    QFormLayout *typeFogVisualLayout;

    //EnvironmentAction->Environment->Weather->Fog->BoundingBox
    QGroupBox *boundingBoxGroupBox;

    //EnvironmentAction->Environment->Weather->Fog->BoundingBox->Center
    QGroupBox *centerGroupBox;
    QLineEdit *xLineEdit2; //x坐标
    QLineEdit *yLineEdit2; //y坐标
    QLineEdit *zLineEdit2; //z坐标
    QFormLayout *centerLayout;

    //EnvironmentAction->Environment->Weather->Fog->BoundingBox->Dimensions
    QGroupBox *dimGroupBox;
    QLineEdit *lenLineEdit; //雾框的长度
    QLineEdit *heightLineEdit; //雾框的高度
    QLineEdit *widthLineEdit; //雾框的宽度
    QFormLayout *dimLayout;

    //EnvironmentAction->Environment->Weather->Precipitation
    QGroupBox *precGroupBox;
    QLineEdit *intensityLineEdit2; //强度
    QComboBox *precComBox; //下雨类型
    QFormLayout *precLayout;

    //EnvironmentAction->Environment->RoadCondition
    QGroupBox *roadConGroupBox;
    QLineEdit *fricScalLineEdit; //摩擦系数
    QFormLayout *roadConLayout;

    //EnvironmentAction->Environment->Properties
    QGroupBox *propertiesGroupBox;

    //EnvironmentAction->Environment->Properties->Property1
    QGroupBox *property1GroupBox;
    QLineEdit *name1LineEdite; //积水
    QComboBox *value1ComBox; // 积水类型
    QFormLayout *name1Layout;

    //EnvironmentAction->Environment->Properties->Property2
    QGroupBox *property2GroupBox;
    QLineEdit *name2LineEdite; //name2 积水量
    QLineEdit *value2LineEdite; //value2 积水类型
    QFormLayout *name2Layout;

    QVBoxLayout *envLayout;
    QVBoxLayout *envChildLayout;
    QVBoxLayout *weatherVLayout;
    QVBoxLayout *properVLayout;
    QVBoxLayout *fogVLayout;
    QVBoxLayout *boundingBoxVLayout;

    //TrafficLight
    QGroupBox *idGroupBox2;
    QLineEdit *idLineEdite2; //交通灯的id
    QFormLayout *idLayout2;

    //1.TrafficLight->SetState节点内容。
    QGroupBox *setStateGroupBox;
    QComboBox *stateComBox2; //设置的状态
    QFormLayout *setStateLayout;

    //2.TrafficLight->SetPhase
    QGroupBox *setPhaseGroupBox;
    QComboBox *stateComBox3;
    QLineEdit *durationLineEdite;
    QFormLayout *setPhaseLayout;

    QVBoxLayout *trafficLightLayout;

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
    QLineEdit *idLineEdite3; //实体的id
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
