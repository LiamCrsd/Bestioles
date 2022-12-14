#include "Behavior.h"

Behavior::Behavior() {
    std::cout<<"Behavior has been created"<<std::endl;
}

double Behavior::calcSpeed(int x,int y,double currentSpeed,double currentDirection, std::vector<std::shared_ptr<IBestiole>> detectedNeighbors){
    //std::cout<<"calcSpeed of Behavior called"<<std::endl;
    return currentSpeed;
}

double Behavior::calcDirection(int x,int y,double currentSpeed,double currentDirection, std::vector<std::shared_ptr<IBestiole>>){
    //std::cout<<"calcDirection of Behavior called"<<std::endl;
    return currentDirection;
}
