#include "Fearful.h"
#include "Config.h"
#include <cmath>
std::pair<double,double> Fearful::calcMeanVec(double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const{
    double r, theta;
    double xm = 0.0;
    double ym = 0.0;
    for (auto & bestiole : detectedNeighbors){
        r = bestiole->getSpeed();
        theta = bestiole->getDirection();
        xm += r*std::cos(theta);
        ym -= r*std::sin(theta);
    }
    if (detectedNeighbors.size()>0){
        xm /= detectedNeighbors.size();
        ym /= detectedNeighbors.size();
    }
    else{
        xm = currentSpeed*std::cos(currentDirection);
        ym = -currentSpeed*std::sin(currentDirection);
    }
    std::pair<double,double> cartesianVect(xm,ym);
    return cartesianVect;
}


double Fearful::calcDirection(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const{
    if (detectedNeighbors.size()>=scaredThreshold){
        std::pair<double,double> cartesianVect = calcMeanVec(currentSpeed,currentDirection,detectedNeighbors);
        return std::atan2(cartesianVect.first,cartesianVect.second); 
    }
    else{
        return Behavior::calcDirection(x,y, currentSpeed,currentDirection, detectedNeighbors);
    }
      
}

double Fearful::calcSpeed(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const{
    if (detectedNeighbors.size()>=scaredThreshold){
        return scaredSpeed*currentSpeed;
    }
    else{
        return Behavior::calcSpeed(x,y,currentSpeed,currentDirection,detectedNeighbors);
    }
}

