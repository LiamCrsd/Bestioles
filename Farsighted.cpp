#include "Farsighted.h"
#include "Config.h"
#include <cmath>
#include <limits>

Farsighted::Farsighted() {
    std::cout<<"Farsighted has been created"<<std::endl;
}

double Farsighted::calcDirection(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors){
    //std::cout<<"calcDirection of Farsighted called"<<std::endl;
    if (detectedNeighbors.size()>0){

        Config& config = Config::GetInstance();

        double distance;
        int neighborsToDodge = 0;
        std::pair<int,int> pos;
        double xm = 0.0;
        double ym = 0.0;
        for (auto & bestiole : detectedNeighbors){
            pos = bestiole->getPos();
            //since we don't have access to current bestiole size, we juste get 2*max size to make sure
            distance = sqrt(pow(x-pos.first,2)
                + pow(y-pos.second,2)) - config.maxSize * 2; 
            if (distance < currentSpeed){
                xm+=pos.first;
                ym+=pos.second;
                neighborsToDodge+=1;
            }
        }
        if (neighborsToDodge > 0) {
            xm = x-xm/neighborsToDodge;
            ym = ym/neighborsToDodge-y;
            return std::atan2(ym,xm);
        } else {
            return currentDirection;
        }
    }
    else{
        return currentDirection;
    }
}