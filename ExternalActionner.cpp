#include "ExternalActionner.h"
#include "Aquarium.h"
#include "BestioleFactory.h"
#include "Stats.h"


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

void ExternalActionner::createBestiole(int index){
    auto listeBestiole = collectionBestiole->getBestiolesList();
    collectionBestiole->addBestiole(factory->createBestiole(listeBestiole.at(index)));
}

void ExternalActionner::changeBehavior(int index, int behaviorType){
    auto bestiole_ptr = collectionBestiole->getBestiolesList().at(index);
    bestiole_ptr->setBehavior(behaviorType);
}

void ExternalActionner::redirectKey(int key) {
    if (key == 97) this->createBestiole();
    if (key == 98) this->killBestiole();
    if (key == 99) this->getReport();
    if (key == 100) this->createBestiole(0);
    if (key == 101) this->changeBehavior(0, 0);
    if (key == 102) this->changeBehavior(0, 1);
    if (key == 103) this->changeBehavior(0, 2);
    if (key == 104) this->changeBehavior(0, 3);
    if (key == 105) this->changeBehavior(0, 4);
    if (key == 106) this->killBestiole(0);
}

void ExternalActionner::killBestiole(){
    if (collectionBestiole->getBestiolesList().size() != 0) {
        int index = rand()/RAND_MAX * collectionBestiole->getBestiolesList().size();
        auto ptr_bestiole = collectionBestiole->getBestiolesList()[index];
        ptr_bestiole->setDead(true);
    }
}

void ExternalActionner::killBestiole(int index){
    auto listeBestiole = collectionBestiole->getBestiolesList();
    collectionBestiole->delBestiole(listeBestiole.at(index));
}

void ExternalActionner::getReport(){
    Stats& stats = Stats::GetInstance();

    std::cout << "Nombre de bestioles en vie : " << collectionBestiole->getBestiolesList().size() << std::endl;
    std::cout << "Nombre de bestioles créées : " << stats.nbCreated << std::endl;
    std::cout << "Nombre de bestioles mortes : " << stats.nbDeaths << std::endl;
    std::cout << "Nombre de collisions : " << stats.nbCollisions << std::endl;
}