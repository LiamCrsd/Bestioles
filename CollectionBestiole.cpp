#include "CollectionBestiole.h"
#include "IBestiole.h"
#include "Stats.h"

#include <cstdlib>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

CollectionBestiole::CollectionBestiole() {
}

CollectionBestiole::~CollectionBestiole() {
}

void CollectionBestiole::addBestiole(std::shared_ptr<IBestiole> ptrBestiole) {
	this->bestioles.push_back(ptrBestiole);
}

void CollectionBestiole::delBestiole(std::shared_ptr<IBestiole> ptrBestiole) {
	Stats& stats = Stats::GetInstance();
	std::vector<std::shared_ptr<IBestiole>>::iterator it = bestioles.begin();

	while (it != bestioles.end() && *it != ptrBestiole) {
		it++;
	}

	if (it != bestioles.end()) {
		bestioles.erase(it);
		stats.nbDeaths++;
	}
}

bool CollectionBestiole::getCollisions(std::shared_ptr<IBestiole> ptrBestiole) {

	Stats& stats = Stats::GetInstance();

	bool isDead = false;
	bool doCollide = false;
	double currDeathrate = ptrBestiole->getDeathRate();
	int currX = ptrBestiole->getX();
	int currY = ptrBestiole->getY();

	for ( std::vector<std::shared_ptr<IBestiole>>::iterator it = bestioles.begin() ; it != bestioles.end() ; ++it )
	{
		if ((*it)->getID() != ptrBestiole->getID()) {
			double currSize = ptrBestiole->getSize();
			int itX = (*it)->getX();
			int itY = (*it)->getY();
			int itSize = (*it)->getSize();

			double distance = pow(pow(currX-itX, 2) + pow(currY-itY, 2), 0.5) - currSize - itSize;
			//cout << "Bestiole " << ptrBestiole->getID() << " is " << distance << " from " << (*it)->getID() << endl;

			if (distance <= 0) {
				doCollide = true;
				stats.nbCollisions++;
				double rollDeath = static_cast<double>( rand() )/RAND_MAX;
				isDead = isDead || (rollDeath < currDeathrate);

				/*if (isDead) {
					cout << ptrBestiole->getID() << " collided with " << (*it)->getID() <<endl;
					cout << "deathRate : " << currDeathrate << endl;
					cout << "rollDeath : " << rollDeath << endl;
					cout << "isDead : " << isDead << endl;
				}*/
			}
		}
	} // for


	if (!isDead && doCollide) {
		ptrBestiole->resolveCollision();
	} else if (isDead) {
		//cout << "Setting bestiole as dead from collision" << endl;
		ptrBestiole->setDead(isDead);
	}



	return doCollide;
}

void CollectionBestiole::processCollisions() {
	for ( std::vector<std::shared_ptr<IBestiole>>::iterator it = bestioles.begin() ; it != bestioles.end() ; ++it )
	{
		getCollisions((*it));
	}
}

void CollectionBestiole::processDetections() {
	for ( std::vector<std::shared_ptr<IBestiole>>::iterator it = bestioles.begin() ; it != bestioles.end() ; ++it )
	{
		std::vector<std::shared_ptr<IBestiole>> detectedBestioles = getDetections((*it));
		(*it)->resolveDetections(detectedBestioles);
	}
}

std::vector<std::shared_ptr<IBestiole>> CollectionBestiole::getDetections(std::shared_ptr<IBestiole> ptrBestiole) {
	std::vector<std::shared_ptr<IBestiole>> detectedBestioles = std::vector<std::shared_ptr<IBestiole>>();
	for ( std::vector<std::shared_ptr<IBestiole>>::iterator it = bestioles.begin() ; it != bestioles.end() ; ++it ) {
		if ((*it)->getID() != ptrBestiole->getID()) {
			if (ptrBestiole->iSeeU(**it)) {
				detectedBestioles.push_back(*it);
			}
		}
	}

	return detectedBestioles;

}

void CollectionBestiole::processDead() {
	Stats& stats = Stats::GetInstance();

	int size_init = bestioles.size();
	bestioles.erase(remove_if(bestioles.begin(),bestioles.end(), [] (std::shared_ptr<IBestiole> b) -> bool {return b -> isDead();} ),bestioles.end());
	stats.nbDeaths += size_init - bestioles.size();
}

void CollectionBestiole::processOld() {
	for ( std::vector<std::shared_ptr<IBestiole>>::iterator it = bestioles.begin() ; it != bestioles.end() ; ++it )
	{
		(*it) -> grow_old();
	}
}