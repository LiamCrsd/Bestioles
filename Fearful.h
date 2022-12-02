#ifndef FEARFUL_H
#define FEARFUL_H
#include "Behavior.h"
#include "IBestiole.h"
#include "Config.h"
#include <utility>
#include <cstdlib>
class Fearful:public Behavior{
    private:
        double scaredSpeed;
        long unsigned int scaredThreshold;
    public:
        Fearful(double scaredSpeed,int scaredThreshold):scaredSpeed(scaredSpeed),scaredThreshold(scaredThreshold){};
        Fearful(){
            Config& config = Config::GetInstance();
            scaredSpeed = static_cast<double>(rand())/RAND_MAX*config.scaredSpeedMax+1;
            scaredThreshold = rand()%(config.scaredThresholdMax-1)+1;
        };
        std::pair<double,double> calcMeanVec(double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const;
        virtual double calcSpeed(int x,int y,double currentSpeed, double currentDirection, std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const override;
        virtual double calcDirection(int x,int y,double currentSpeed,double currentDirection, std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const override;
};
#endif