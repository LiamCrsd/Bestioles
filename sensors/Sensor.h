#ifndef _SENSOR_H_
#define _SENSOR_H_
class Sensor
{
protected:
    double detectionDistance;
    double detectionRate;
public:
    virtual bool isDetected(int xThis, int ythis, double headingThis,
    int xBestiole, int yBestiole, double camouflageBestiole);
};
#endif