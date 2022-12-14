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
    behavior = std::unique_ptr<Behavior>(new Behavior());
    switchRate = static_cast<double>(rand())/RAND_MAX*Config::GetInstance().switchRateMax;
}

void MultiplePersonnality::switchBehavior(){
    std::random_device rd;
    std::mt19937 gen(rd());
    if (std::bernoulli_distribution(switchRate)(gen)){
        std::cout<<"Switch personnality for " << this << std::endl;
        int random = rand()%4;
        if (random==0){
            std::cout<< "Gregarious" << std::endl;
            behavior = std::unique_ptr<Behavior>(new Gregarious());
        }
        else if (random==1){
            std::cout<< "Fearful" << std::endl;
            behavior = std::unique_ptr<Behavior>(new Fearful());
        }
        else if (random==2){
            std::cout<< "Kamikaze" << std::endl;
            behavior = std::unique_ptr<Behavior>(new Kamikaze());
        }
        else{
            std::cout<< "Farsighted" << std::endl;
            behavior = std::unique_ptr<Behavior>(new Farsighted());
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
