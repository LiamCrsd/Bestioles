#include "Eyes.h"
#include <cmath>
#include <iostream>

Eyes::Eyes(double distance, double rate, double view) {
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
