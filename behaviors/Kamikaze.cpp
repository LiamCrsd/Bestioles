#include "Kamikaze.h"
#include <cmath>
#include <limits>

Kamikaze::Kamikaze(){
    //std::cout<<"Kamikaze has been created"<<std::endl;
}

double Kamikaze::calcDirection(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors){
    //std::cout<<"calcDirection of Kamikaze called"<<std::endl;
    double minDistance = std::numeric_limits<double>::max() ;
    std::shared_ptr<IBestiole> closestBestiole;
    std::pair<int,int> pos;
    double distance;
    if (detectedNeighbors.size()>0){
        for (auto & bestiole : detectedNeighbors){
            pos = bestiole->getPos();
            distance = sqrt(pow(x-pos.first,2)
                + pow(y-pos.second,2));
            if (distance<minDistance){
                minDistance = distance;
                closestBestiole = bestiole;
            }
        }
        pos = closestBestiole->getPos();
        return fmod(std::atan2(y-pos.second,pos.first-x),2*M_PI);
    }
    else{
        return currentDirection;
    }
}