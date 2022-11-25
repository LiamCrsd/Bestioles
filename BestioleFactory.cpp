#include "BestioleFactory.h"
#include "Bestiole.h"
#include <memory>

shared_ptr<Bestiole> BestioleFactory::createBestiole(){
    std::shared_ptr<Bestiole> bestiole (new Bestiole());
    return bestiole;
}

shared_ptr<Bestiole> BestioleFactory::createBestiole(const Bestiole& bestiole){
    std::shared_ptr<Bestiole> bestiole_ptr (new Bestiole(bestiole));
    return bestiole_ptr;
}


