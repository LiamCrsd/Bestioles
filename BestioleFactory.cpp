#include "BestioleFactory.h"
#include "Bestiole.h"
#include <memory>
#include <stdexcept>

std::shared_ptr<IBestiole> BestioleFactory::createBestiole(){
    std::shared_ptr<IBestiole> bestiole (new Bestiole());
    return bestiole;
}

std::shared_ptr<IBestiole> BestioleFactory::createBestiole(const Bestiole& bestiole){
    std::shared_ptr<IBestiole> bestiole_ptr (new Bestiole(bestiole));
    return bestiole_ptr;
}

std::shared_ptr<IBestiole> BestioleFactory::createBestiole(int type){
    throw std::invalid_argument("Not implemented");
}


