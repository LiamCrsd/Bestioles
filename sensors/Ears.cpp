#include "Ears.h"
#include <iostream>
Ears::Ears(double distance, double rate) {
    //std::cout << "const ears with dist" << distance << std::endl;
    detectionDistance = distance;
    detectionRate = rate;
}

bool Ears::isDetected(int xThis, int yThis, double headingThis, 
int xTarget, int yTarget, double camouflageTarget) {
    return Sensor::isDetected(xThis, yThis, headingThis, xTarget, yTarget, camouflageTarget);
}