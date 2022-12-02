#include "Farsighted.h"
#include <cmath>
#include <limits>
double Farsighted::calcDirection(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const{
    double minDistance = std::numeric_limits<double>::max() ;
    std::shared_ptr<IBestiole> closestBestiole; 
    double distance;
    std::pair<int,int> pos;
    for (auto & bestiole : detectedNeighbors){
        pos = bestiole->getPos();
        distance = sqrt(pow(x-pos.first,2))
            + pow(y-pos.second,2);
        if (distance<minDistance){
            minDistance = distance;
            closestBestiole = bestiole;
        }
    }
    pos = closestBestiole->getPos();
    return std::atan2(x-pos.first,y-pos.second);

}