#include "ExternalActionner.h"
#include "Aquarium.h"
#include "BestioleFactory.h"


ExternalActionner::ExternalActionner(){

}

ExternalActionner::ExternalActionner(Ecosystem *flotte){
    this->factory = flotte->getBestioleFactory();
    this->collectionBestiole = flotte->getCollection();
}

ExternalActionner::~ExternalActionner( void )
{

   cout << "dest ExternalActionner" << endl;

}

void ExternalActionner::createBestiole(){
    collectionBestiole->addBestiole(factory->createBestiole());
}

void ExternalActionner::redirectKey(int key) {
    if (key == 97) this->createBestiole();
}