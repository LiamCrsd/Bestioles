#ifndef GREGARIOUS_H
#define GREGARIOUS_H
#include "Behavior.h"
#include "IBestiole.h"
#include <utility>

class Gregarious:public Behavior{
    public:
        Gregarious(){std::cout<<"Gregarious has been created"<<std::endl;}
        std::pair<double,double> calcMeanVec(double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const;
        virtual double calcDirection(int x, int y,double currentSpeed,double currentDirection, std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const override;
};
#endif