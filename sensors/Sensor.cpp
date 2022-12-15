#include "Sensor.h"
#include "UImg.h"
#include <iostream>
#include <cmath>

bool Sensor::isDetected(int xThis, int yThis, double headingThis, 
    int xTarget, int yTarget, double camouflageTarget) {
        int distance = sqrt(pow(xTarget-xThis, 2) + pow(yTarget-yThis, 2));
        if (detectionRate > camouflageTarget) {
            return (distance <= Sensor::detectionDistance);
        };
        return false; 
}

void Sensor::drawSensor(UImg& support, int x, int y, double size, double direction, T* color) {}
