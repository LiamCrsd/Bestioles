#include "Fearful.h"
#include "Config.h"
#include <cmath>
std::pair<double,double> Fearful::calcBarycenterVec(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const{
    double xm = 0.0;
    double ym = 0.0;
    if (detectedNeighbors.size()>0){
        for (auto & bestiole : detectedNeighbors){
            xm += bestiole->getX();
            ym += bestiole->getY();
        }
        xm = xm/detectedNeighbors.size()-x;
        ym = ym/detectedNeighbors.size()-y;
    }
    else{
        xm = currentSpeed*std::cos(currentDirection);
        ym = currentSpeed*std::sin(currentDirection);
    }
    std::pair<double,double> cartesianVect(xm,ym);
    return cartesianVect;
}


double Fearful::calcDirection(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const{
    if (detectedNeighbors.size()>=scaredThreshold){
        std::pair<double,double> barycenterVect = calcBarycenterVec(x,y,currentSpeed,currentDirection,detectedNeighbors);
        double barycenterDirection = fmod(std::atan2(barycenterVect.second,barycenterVect.first),2*M_PI);
        return fmod(barycenterDirection+M_PI,2*M_PI); 
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

