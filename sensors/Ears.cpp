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

void Ears::drawSensor(UImg& support, int x, int y, double size, double direction, T* color) {
    
    double         xl = x + cos( direction )*size/2 + cos( direction + M_PI/2 )*size/2;
    double         yl = y - sin( direction )*size/2 - sin( direction + M_PI/2 )*size/2;
    double         xr = x + cos( direction )*size/2 + cos( direction - M_PI/2 )*size/2;
    double         yr = y - sin( direction )*size/2 - sin( direction - M_PI/2 )*size/2;

    support.draw_circle( xl, yl, size/5, color);
    support.draw_circle( xr, yr, size/5, color);
}