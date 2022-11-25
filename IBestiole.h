#ifndef _BESTIOLE_INTERFACE_H_
#define _BESTIOLE_INTERFACE_H_

class IBestiole :
{
	virtual bool isDead() = 0;
	virtual bool atBorder() = 0;
	virtual void resolveCollision() = 0;
	virtual void resolveDetections(std::vector<Bestiole*> detectedNeighbors) = 0;
	virtual bool doClone() = 0;
	virtual void move() = 0;
}

#endif