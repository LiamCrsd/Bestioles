#include "MultiplePersonnality.h"
#include "Behavior.h"
#include "Gregarious.h"
#include "Fearful.h"
#include "Kamikaze.h"
#include "Farsighted.h"
#include "Config.h"
#include <random>
MultiplePersonnality::MultiplePersonnality(){
    std::cout<<"Multiple personnality has been created"<<std::endl;
    behavior = std::shared_ptr<Behavior>(new Behavior());
    switchRate = static_cast<double>(rand())/RAND_MAX*Config::GetInstance().switchRateMax;
}

void MultiplePersonnality::switchBehavior(){
    std::random_device rd;
    std::mt19937 gen(rd());
    if (std::bernoulli_distribution(switchRate)(gen)){
        std::cout<<"Switch personnality"<<std::endl;
        int random = rand()%4;
        if (random==0){
            behavior = std::shared_ptr<Behavior>(new Gregarious());
        }
        else if (random==1){
            behavior = std::shared_ptr<Behavior>(new Fearful());
        }
        else if (random==2){
            behavior = std::shared_ptr<Behavior>(new Kamikaze());
        }
        else{
            behavior = std::shared_ptr<Behavior>(new Farsighted());
        }
    }
}

double MultiplePersonnality::calcSpeed(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors){
    switchBehavior();
    return behavior->calcSpeed(x,y,currentSpeed,currentDirection,detectedNeighbors);
}

double MultiplePersonnality::calcDirection(int x,int y,double currentSpeed,double currentDirection,std::vector<std::shared_ptr<IBestiole>> detectedNeighbors){
    return behavior->calcDirection(x,y,currentSpeed,currentDirection,detectedNeighbors);
}
