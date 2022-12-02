#include "Ears.h"
#include <iostream>
Ears::Ears(double distance, double rate) {
    detectionDistance = distance;
    detectionRate = rate;
}

bool Ears::isDetected(int xThis, int yThis, double headingThis, 
int xTarget, int yTarget, double camouflageTarget) {
    return Sensor::isDetected(xThis, yThis, headingThis, xTarget, yTarget, camouflageTarget);
}