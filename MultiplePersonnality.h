#ifndef MULTIPLEPERSONNALITY_H
#define MULTIPLEPERSONNALITY_H
#include "Behavior.h"
#include "IBestiole.h"

class MultiplePersonnality:public Behavior{
    private:
        double switchRate;
        std::unique_ptr<Behavior> behavior;
        void switchBehavior(double rate);
    public:
        MultiplePersonnality();
        virtual double calcSpeed(int x,int y, double currentSpeed,double currentDirection, std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) override;
        virtual double calcDirection(int x, int y,double currentSpeed,double currentDirection, std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) override;
};
#endif