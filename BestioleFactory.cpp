#include "BestioleFactory.h"
#include "Bestiole.h"
#include "Config.h"
#include <memory>
#include <stdexcept>
#include "accessories/Accessory.h"
#include "accessories/Shell.h"
#include "accessories/Fins.h"
#include "accessories/Camouflage.h"
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


    std::vector<std::shared_ptr<Accessory>> accessories; 

    if (static_cast<double>( rand() )/RAND_MAX < 1/3) {
        std::shared_ptr<Shell> shellPtr (new Shell((static_cast<double>( rand() )/RAND_MAX)*(config.resistanceFactorMax- config.resistanceFactorMin) + config.resistanceFactorMin, (static_cast<double>( rand() )/RAND_MAX)*(config.slowFactorMax-config.slowFactorMin)+config.slowFactorMin));
        accessories.push_back(shellPtr);
        //cout << "Adding shell to bestiole with factor " << shellPtr->getResistanceFactor() << endl;
    }
    if (static_cast<double>( rand() )/RAND_MAX < 1/3) {
        std::shared_ptr<Fins> finsPtr (new Fins((static_cast<double>( rand() )/RAND_MAX)*(config.speedFactorMax - config.speedFactorMin) + config.speedFactorMin));
        accessories.push_back(finsPtr);
    }
    if (static_cast<double>( rand() )/RAND_MAX < 1/3) {
        std::shared_ptr<Camouflage> camouflagePtr (new Camouflage((static_cast<double>( rand() )/RAND_MAX)*(config.camouflageFactorMax - config.camouflageFactorMin) + config.camouflageFactorMin));
        accessories.push_back(camouflagePtr);
    }


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
    std::shared_ptr<IBestiole> bestiole (new Bestiole(xpos, ypos, direction, speed, size, ageLim, cloneRate, deathRate, sensors, accessories));
    return bestiole;
}

std::shared_ptr<IBestiole> BestioleFactory::createBestiole(const Bestiole& bestiole){
    std::shared_ptr<IBestiole> bestiole_ptr (new Bestiole(bestiole));
    return bestiole_ptr;
}

std::shared_ptr<IBestiole> BestioleFactory::createBestiole(int type){
    throw std::invalid_argument("Not implemented");
}


    