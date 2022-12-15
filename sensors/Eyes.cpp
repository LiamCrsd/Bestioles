#include "Eyes.h"
#include "UImg.h"
#include <cmath>
#include <iostream>

Eyes::Eyes(double distance, double rate, double view) {
    //std::cout << "const eyes with dist" << distance << " and FOV " << view << std::endl;
    detectionDistance = distance;
    detectionRate = rate;
    fieldView = view;
}


bool Eyes::isDetected(int xThis, int yThis, double headingThis, 
int xTarget, int yTarget, double camouflageTarget) {
    bool distanceCondition = Sensor::isDetected(xThis, yThis, headingThis, xTarget, yTarget, camouflageTarget);
    if (distanceCondition) {
        int x3 = xThis + cos(headingThis);
        int y3 = yThis + sin(headingThis);
        double ab = sqrt(pow(xTarget-xThis, 2) + pow(yTarget-yThis, 2));
        double ac = sqrt(pow(x3-xThis, 2) + pow(y3-yThis, 2));
        double bc = sqrt(pow(xTarget-x3, 2) + pow(yTarget-y3, 2));
        double angle = abs(acos((pow(bc, 2) - pow(ab, 2) - pow(ac, 2))/(2*ab*ac)));
        return angle <= Eyes::fieldView;
    };
    return false;
}

void Eyes::drawSensor(UImg& support, int x, int y, double size, double direction, T* color) {
    
    double         xl = x + cos( direction )*size/1.5 + cos( direction + M_PI/2 )*size/3.4;
    double         yl = y - sin( direction )*size/1.5 - sin( direction + M_PI/2 )*size/3.4;
    double         xr = x + cos( direction )*size/1.5 + cos( direction - M_PI/2 )*size/3.4;
    double         yr = y - sin( direction )*size/1.5 - sin( direction - M_PI/2 )*size/3.4;

    int black[3]{0, 0, 0};
    support.draw_circle( xl, yl, size/10, black);
    support.draw_circle( xr, yr, size/10, black);
}
