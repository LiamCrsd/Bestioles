#include "BestioleFactory.h"
#include "Bestiole.h"
#include "Config.h"
#include <memory>
#include <stdexcept>
#include "sensors/Eyes.h"
#include "sensors/Ears.h"
#include "sensors/Sensor.h"


std::shared_ptr<IBestiole> BestioleFactory::createBestiole(){

    Config& config = Config::GetInstance();

    int xpos = static_cast<double>( rand() )/RAND_MAX*config.width;
    int ypos = static_cast<double>( rand() )/RAND_MAX*config.height;
    double speed = static_cast<double>( rand() )/RAND_MAX*(config.maxSpeed - config.minSpeed) + config.minSpeed;
    double direction = static_cast<double>( rand() )/RAND_MAX*2*M_PI;
    double size = static_cast<double>( rand() )/RAND_MAX*(config.maxSize - config.minSize) + config.minSize;
    int ageLim = static_cast<double>( rand() )/RAND_MAX*(config.ageMax - config.ageMin) + config.ageMin;
    double deathRate = static_cast<double>( rand() )/RAND_MAX*config.deathRateMax;
    double cloneRate = static_cast<double>( rand() )/RAND_MAX*config.cloneRateMax;
    int behaviorIndex = 1;//rand()%5;
    std::vector<std::shared_ptr<Sensor>> sensors;
    if (static_cast<double>( rand() )/RAND_MAX > 0.5) {
        std::shared_ptr<Ears> ears (new Ears(
            static_cast<double>( rand() )/RAND_MAX*(config.detectionDistanceMax - config.detectionDistanceMin) + config.detectionDistanceMin,
            static_cast<double>( rand() )/RAND_MAX*(config.detectionRateMax - config.detectionRateMin) + config.detectionRateMin
        ));
        sensors.push_back(ears);
    }
    if (static_cast<double>( rand() )/RAND_MAX > 0.5) {
        std::shared_ptr<Eyes> eyes (new Eyes(
            static_cast<double>( rand() )/RAND_MAX*(config.detectionDistanceMax - config.detectionDistanceMin) + config.detectionDistanceMin, 
            static_cast<double>( rand() )/RAND_MAX*(config.detectionRateMax - config.detectionRateMin) + config.detectionRateMin, 
            static_cast<double>( rand() )/RAND_MAX*(config.fieldViewMax - config.fieldViewMin) + config.fieldViewMin
        ));
        sensors.push_back(eyes);
    }
    std::shared_ptr<IBestiole> bestiole (new Bestiole(xpos, ypos, direction, speed, size, ageLim, cloneRate, deathRate,behaviorIndex, sensors));
    return bestiole;
}

std::shared_ptr<IBestiole> BestioleFactory::createBestiole(const Bestiole& bestiole){
    std::shared_ptr<IBestiole> bestiole_ptr (new Bestiole(bestiole));
    return bestiole_ptr;
}

std::shared_ptr<IBestiole> BestioleFactory::createBestiole(int type){
    throw std::invalid_argument("Not implemented");
}


    