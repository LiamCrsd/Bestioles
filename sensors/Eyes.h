#ifndef _EYES_H_
#define _EYES_H_

#include "Sensor.h"

class Eyes : public Sensor
{
private:
    double fieldView;
public:
    Eyes(double detectionDistance, double detectionRate, double fieldView);
    bool isDetected(int xThis, int yThis, double headingThis,
    int xTarget, int yTarget, double camouflageTarget);
};
#endif

