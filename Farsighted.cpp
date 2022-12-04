#include "Farsighted.h"
#include <cmath>
#include <limits>
double Farsighted::calcDirection(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const{
    if (detectedNeighbors.size()>0){

        double distance;
        std::pair<int,int> pos;
        double xm = 0.0;
        double ym = 0.0;
        for (auto & bestiole : detectedNeighbors){
            pos = bestiole->getPos();
            distance = sqrt(pow(x-pos.first,2))
                + pow(y-pos.second,2);
            if (distance < currentSpeed){
                xm+=pos.first;
                ym+=pos.second;
            }
        }
        xm = x-xm/detectedNeighbors.size();
        ym = y-ym/detectedNeighbors.size();
        return std::atan2(ym,xm);
    }
    else{
        return currentDirection;
    }
}