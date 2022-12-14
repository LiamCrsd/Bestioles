#ifndef FEARFUL_H
#define FEARFUL_H
#include "Behavior.h"
#include "IBestiole.h"
#include "Config.h"
#include <utility>
#include <cstdlib>
#include <algorithm>
class Fearful:public Behavior{
    private:
        static const int SCARED_MEMORY = 7;
        
        int currentScaredMemory;
        double scaredSpeed;
        long unsigned int scaredThreshold;
        std::pair<double,double> calcBarycenterVec(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors);
        
    public:
        Fearful(double scaredSpeed,int scaredThreshold):scaredSpeed(scaredSpeed),scaredThreshold(scaredThreshold){};
        Fearful();
        virtual double calcSpeed(int x,int y,double currentSpeed, double currentDirection, std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) override;
        virtual double calcDirection(int x,int y,double currentSpeed,double currentDirection, std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) override;
};
#endif