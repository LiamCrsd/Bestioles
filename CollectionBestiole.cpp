#include "CollectionBestiole.h"
#include "IBestiole.h"

#include <vector>
#include <memory>

CollectionBestiole::CollectionBestiole() {
}

CollectionBestiole::~CollectionBestiole() {
}

void CollectionBestiole::addBestiole(std::shared_ptr<IBestiole> ptrBestiole) {
	this->bestioles.push_back(ptrBestiole);
}

void CollectionBestiole::delBestiole(std::shared_ptr<IBestiole> ptrBestiole) {
	std::vector<std::shared_ptr<IBestiole>>::iterator it = bestioles.begin();

	while (it != bestioles.end() && *it != ptrBestiole) {
		it++;
	}

	if (it != bestioles.end()) {
		bestioles.erase(it);
	}
}

bool CollectionBestiole::getCollisions(std::shared_ptr<IBestiole> ptrBestiole) {
	for ( std::vector<std::shared_ptr<IBestiole>>::iterator it = bestioles.begin() ; it != bestioles.end() ; ++it )
	{
		
		

	} // for
}

void CollectionBestiole::processCollisions() {

}