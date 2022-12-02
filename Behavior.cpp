#include "Behavior.h"

double Behavior::calcSpeed(int x,int y,double currentSpeed,double currentDirection, std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const{
    return currentSpeed;
}

double Behavior::calcDirection(int x,int y,double currentSpeed,double currentDirection, std::vector<std::shared_ptr<IBestiole>>)const {
    return currentDirection;
}
