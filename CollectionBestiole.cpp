#include "CollectionBestiole.h"
#include "Bestiole.h"

CollectionBestiole::CollectionBestiole() {
	this->bestioles = new std::vector<Bestiole*>();

}

CollectionBestiole::~CollectionBestiole() {
	delete bestioles;
}

CollectionBestiole::add(Bestiole bestiole) {
	this->bestioles.add(Bestiole);
}

CollectionBestiole::delete(Bestiole *bestiole) {
	for ( std::vector<Bestiole>::iterator it = bestioles.begin(); it != bestioles.end(); it++)
	{
		if (std)
	}
}