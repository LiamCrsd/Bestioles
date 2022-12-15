#ifndef _SENSOR_H_
#define _SENSOR_H_

#include "UImg.h"
class Sensor
{
protected:
    double detectionDistance;
    double detectionRate;
public:
    virtual bool isDetected(int xThis, int ythis, double headingThis, int xBestiole, int yBestiole, double camouflageBestiole);
    virtual void drawSensor(UImg& support, int x, int y, double size, double direction, T* color);
};
#endif