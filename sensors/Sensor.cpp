#include "Sensor.h"

bool Sensor::isDetected(int xThis, int yThis, double headingThis, 
    int xTarget, int yTarget, double camouflageTarget) {
        int distance = sqrt(pow(xTarget-xThis, 2) + pow(yTarget-yThis, 2));
        if (detectionRate > camouflageTarget) {
            return (distance <= Ears::detectionDistance);
        };
        return false; 
}