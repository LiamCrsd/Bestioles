#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include "IBestiole.h"
#include <vector>
#include <memory>
class Behavior{
    public:
        virtual double calcSpeed(int x,int y,double currentSpeed,double currentDirection, std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const;
        virtual double calcDirection(int x,int y,double currentSpeed,double currentDirection, std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const;
};
#endif