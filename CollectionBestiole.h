#ifndef _COLL_BESTIOLES_H_
#define _COLL_BESTIOLES_H_

using namespace std;

class CollectionBestiole :
{

private:
	std::vector<Bestiole> bestioles;

public:
	CollectionBestiole();
	~CollectionBestiole();

	void add(Bestiole bestiole);
	void del(Bestiole *bestiole);

	std::vector<Bestiole*> getCollisions(Bestiole bestiole);
	std::vector<Betsiole*> getDetections(Bestiole bestiole);
	void processCollisions();
	std::vector<Bestiole*> processDetections();
	void processDeaths();

};

#endif