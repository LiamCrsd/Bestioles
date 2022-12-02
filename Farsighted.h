#ifndef FARSIGHTED_H
#define FARSIGHTED_H
#include "Behavior.h"
#include "IBestiole.h"
class Farsighted:public Behavior{
    public:
        virtual double calcDirection(int x, int y,double currentSpeed,double currentDirection, std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const override;
};
#endif