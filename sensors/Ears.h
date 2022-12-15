#ifndef _EARS_H_
#define _EARS_H_

#include "Sensor.h"

class Ears : public Sensor
{
public:
    Ears(double detectionDistance, double detectionRate);
    bool isDetected(int xThis, int yThis, double headingThis, 
    int xTarget, int yTarget, double camouflageTarget);
    void drawSensor(UImg& support, int x, int y, double size, double direction, T* color);
};
#endif