#ifndef KAMIKAZE_H
#define KAMIKAZE_H
#include "Behavior.h"
#include "IBestiole.h"

class Kamikaze:public Behavior{
    public:
        Kamikaze();
        virtual double calcDirection(int x, int y,double currentSpeed,double currentDirection, std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) override;
};
#endif