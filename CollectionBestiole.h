#ifndef _COLL_BESTIOLES_H_
#define _COLL_BESTIOLES_H_

#include "IBestiole.h"
#include <vector>
#include <memory>

class CollectionBestiole
{

private:
	std::vector<std::shared_ptr<IBestiole>> bestioles;

public:
	CollectionBestiole();
	~CollectionBestiole();

	void addBestiole(std::shared_ptr<IBestiole> ptrBestiole);
	void delBestiole(std::shared_ptr<IBestiole> ptrBestiole);

	bool getCollisions(std::shared_ptr<IBestiole> ptrBestiole);
	std::vector<std::shared_ptr<IBestiole>> getDetections(std::shared_ptr<IBestiole> ptrBestiole);
	void processCollisions();
	void processDetections();
	void processDeaths();
	std::vector<std::shared_ptr<IBestiole>> getBestiolesList() { return bestioles; };
	void processDead();
	void processOld();

};

#endif
