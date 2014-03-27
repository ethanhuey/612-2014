#ifndef AUTONOMOUS_H   // collabedit.com/rg9ek
#define AUTONOMOUS_H
#include "DriveTrain.h"
#include "Shooter.h"
#include <Timer.h>

// the auto methods return true when completed

class Autonomous
{
public:
    Autonomous(main_robot* robot);
    ~Autonomous();
    bool moveForward(double dist);
    bool turn();
    bool tilt(double);
    bool wormPull();
    bool smartFire();
    bool determineHot();

    bool timePassed(float time);        //time measured in seconds
    Timer* timer;
    Timer* shotTimer;
    enum State {DRIVE_AIM_WINCH, FINE_AIM, IS_HOT, SMART_FIRE, BASIC_DRIVE, IDLE, DONE};
    State stage;
    State previousStage;
    main_robot* robot;
    NetworkTable* table;

    void updateHighGoal();
    void updateBasicDrive();

    static const double DISTANCE = 151;
    static const double DEGREES_TURN = 25;
    static const double HIGHGOAL_AUTOANGLE = 40;

};
#endif //AUTONOMOUS_H


