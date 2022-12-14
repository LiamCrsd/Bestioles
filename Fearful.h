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
    public:
        Fearful(double scaredSpeed,int scaredThreshold):scaredSpeed(scaredSpeed),scaredThreshold(scaredThreshold){};
        Fearful(){
            std::cout<<"Fearful has been created"<<std::endl;
            Config& config = Config::GetInstance();
            scaredSpeed = static_cast<double>(rand())/RAND_MAX*config.scaredSpeedMax+1;
            scaredThreshold = rand()%(std::max(config.scaredThresholdMax-1,1))+1;
        };
        std::pair<double,double> calcBarycenterVec(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors);
        virtual double calcSpeed(int x,int y,double currentSpeed, double currentDirection, std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) override;
        virtual double calcDirection(int x,int y,double currentSpeed,double currentDirection, std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) override;
};
#endif