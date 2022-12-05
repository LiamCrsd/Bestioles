#include "Kamikaze.h"
#include <cmath>
#include <limits>
double Kamikaze::calcDirection(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const{
    double minDistance = std::numeric_limits<double>::max() ;
    std::shared_ptr<IBestiole> closestBestiole;
    std::pair<int,int> pos;
    double distance;
    std::cout<<"current direction:"<<currentDirection<<std::endl;
    if (detectedNeighbors.size()>0){
        std::cout<<"current x:"<<x<<std::endl;
        std::cout<<"current y:"<<y<<std::endl;
        for (auto & bestiole : detectedNeighbors){
            pos = bestiole->getPos();
            std::cout<<"detected bestiole x:"<<pos.first<<std::endl;
            std::cout<<"detected bestiole y:"<<pos.second<<std::endl;
            distance = sqrt(pow(x-pos.first,2)
                + pow(y-pos.second,2));
            std::cout<<"current minDistance:"<<minDistance<<std::endl;
            std::cout<<"current bestiole distance:"<<distance<<std::endl;
            if (distance<minDistance){
                minDistance = distance;
                closestBestiole = bestiole;
            }
            std::cout<<"after detection minDistance:"<<minDistance<<std::endl;
        }
        pos = closestBestiole->getPos();
        double theta = fmod(std::atan2(y-pos.second,pos.first-x),2*M_PI);
        std::cout<<"closest bestiole direction:"<<theta<<std::endl;
        std::cout<<"x after direction:"<<x+minDistance*std::cos(theta)<<std::endl;
        std::cout<<"y after direction:"<<y-minDistance*std::sin(theta)<<std::endl;
        return fmod(std::atan2(y-pos.second,pos.first-x),2*M_PI);
    }
    else{
        return currentDirection;
    }
}