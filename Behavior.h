#ifndef BEHAVIOR_H
#define BEHAVIOR_H

#include "IBestiole.h"
#include <vector>
#include <memory>
#include <iostream>
class Behavior{
    public:
        Behavior(){std::cout<<"Behavior has been created"<<std::endl;};
        ~Behavior() = default;
        virtual double calcSpeed(int x,int y,double currentSpeed,double currentDirection, std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const;
        virtual double calcDirection(int x,int y,double currentSpeed,double currentDirection, std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const;
};
#endif