#include "Gregarious.h"
#include <cmath>

Gregarious::Gregarious() {
    //std::cout<<"Gregarious has been created"<<std::endl;
}

std::pair<double,double> Gregarious::calcMeanVec(double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors){
    double theta;
    double xm = 0.0;
    double ym = 0.0;
    for (auto & bestiole : detectedNeighbors){
        theta = bestiole->getDirection();
        xm += std::cos(theta);
        ym += std::sin(theta);
    }
    if (detectedNeighbors.size()>0){
        xm /= detectedNeighbors.size();
        ym /= detectedNeighbors.size();
    }
    else{
        xm = std::cos(currentDirection);
        ym = std::sin(currentDirection);
    }
    std::pair<double,double> cartesianVect(xm,ym);
    return cartesianVect;
}

double Gregarious::calcDirection(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors){
    //std::cout<<"calcDirection of Gregarious called"<<std::endl;
    std::pair<double,double> cartesianVect = calcMeanVec(currentDirection,detectedNeighbors);
    return fmod(std::atan2(cartesianVect.second,cartesianVect.first),2*M_PI);
} 

