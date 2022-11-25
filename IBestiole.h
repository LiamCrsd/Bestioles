#ifndef _BESTIOLE_INTERFACE_H_
#define _BESTIOLE_INTERFACE_H_

#include <vector>

class IBestiole
{
public:
	virtual bool isDead();
	virtual bool atBorder();
	virtual void resolveCollision();
	virtual void resolveDetections(std::vector<IBestiole*> detectedNeighbors);
	virtual bool doClone();
	virtual void move();
};

#endif