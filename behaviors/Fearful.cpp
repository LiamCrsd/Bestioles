#include "Fearful.h"
#include "Config.h"
#include <cmath>

Fearful::Fearful() {
    //std::cout<<"Fearful has been created"<<std::endl;
    Config& config = Config::GetInstance();
    scaredSpeed = static_cast<double>(rand())/RAND_MAX*config.scaredSpeedMax+1;
    scaredThreshold = rand()%(std::max(config.scaredThresholdMax-1,1))+1;
}

std::pair<double,double> Fearful::calcBarycenterVec(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors){
    double xm = 0.0;
    double ym = 0.0;
    if (detectedNeighbors.size()>0){
        for (auto & bestiole : detectedNeighbors){
            xm += bestiole->getX();
            ym += bestiole->getY();
        }
        xm = xm/detectedNeighbors.size()-x;
        ym = y-ym/detectedNeighbors.size();
    }
    else{
        xm = currentSpeed*std::cos(currentDirection);
        ym = -currentSpeed*std::sin(currentDirection);
    }
    std::pair<double,double> cartesianVect(xm,ym);
    return cartesianVect;
}


double Fearful::calcDirection(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors){
    //std::cout<<"calcDirection of Fearful called"<<std::endl;
    if (detectedNeighbors.size()>=scaredThreshold){
        std::pair<double,double> barycenterVect = calcBarycenterVec(x,y,currentSpeed,currentDirection,detectedNeighbors);
        double barycenterDirection = fmod(std::atan2(barycenterVect.second,barycenterVect.first),2*M_PI);
        return fmod(barycenterDirection+M_PI,2*M_PI); 
    }
    else{
        return Behavior::calcDirection(x,y, currentSpeed,currentDirection, detectedNeighbors);
    }
      
}

double Fearful::calcSpeed(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors){
    //std::cout<<"calcSpeed of Fearful called"<<std::endl;
    if (detectedNeighbors.size()>=scaredThreshold || currentScaredMemory > 0){
        if (detectedNeighbors.size()>=scaredThreshold) {
            currentScaredMemory = SCARED_MEMORY;
        } else {
            currentScaredMemory -= 1;
        }
        return scaredSpeed*currentSpeed;
    }
    else{
        return Behavior::calcSpeed(x,y,currentSpeed,currentDirection,detectedNeighbors);
    }
}

