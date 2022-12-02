#include "MultiplePersonnality.h"
#include "Gregarious.h"
#include "Fearful.h"
#include "Kamikaze.h"
#include "Farsighted.h"
#include "Config.h"
#include <random>
MultiplePersonnality::MultiplePersonnality(){
    behavior = randomBehavior();
    switchRate = static_cast<double>(rand())/RAND_MAX*Config::GetInstance().switchRateMax;
}
Behavior MultiplePersonnality::randomBehavior(){
    Behavior behav;
    int random = rand()%4;
    if (random==0){
        behav = Gregarious();
    }
    else if (random==1){
        behav = Fearful();
    }
    else if (random==2){
        behav = Kamikaze();
    }
    else{
        behav = Farsighted();
    }
    return behav;
}
void MultiplePersonnality::switchBehavior(){
    std::random_device rd;
    std::mt19937 gen(rd());
    if (std::bernoulli_distribution(switchRate)(gen)){
        behavior = randomBehavior();
    }
}

double MultiplePersonnality::calcSpeed(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const{
    return behavior.calcSpeed(x,y,currentSpeed,currentDirection,detectedNeighbors);
}

double MultiplePersonnality::calcDirection(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors) const{
    return behavior.calcDirection(x,y,currentSpeed,currentDirection,detectedNeighbors);
}
