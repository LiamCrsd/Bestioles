#include "Gregarious.h"
#include <cmath>

std::pair<double,double> Gregarious::calcMeanVec(double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const{
    double r, theta;
    double xm = 0.0;
    double ym = 0.0;
    for (auto & bestiole : detectedNeighbors){
        r = bestiole->getSpeed();
        theta = bestiole->getDirection();
        xm += r*std::cos(theta);
        ym += r*std::sin(theta);
    }
    if (detectedNeighbors.size()>0){
        xm /= detectedNeighbors.size();
        ym /= detectedNeighbors.size();
    }
    else{
        xm = currentSpeed*std::cos(currentDirection);
        ym = currentSpeed*std::sin(currentDirection);
    }
    std::pair<double,double> cartesianVect(xm,ym);
    return cartesianVect;
}

double Gregarious::calcDirection(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const{
    std::pair<double,double> cartesianVect = calcMeanVec(currentSpeed,currentDirection,detectedNeighbors);
    return fmod(std::atan2(cartesianVect.second,cartesianVect.first),2*M_PI);
} 

