#ifndef _BESTIOLE_INTERFACE_H_
#define _BESTIOLE_INTERFACE_H_

#include "UImg.h"
#include <vector>
#include <memory>

class IBestiole
{
public:
	virtual ~IBestiole() {};

	virtual bool isDead() const =0;
	virtual void setDead(bool isDead)=0;
	virtual bool atBorder()=0;
	virtual void resolveCollision()=0;
	virtual void resolveDetections(std::vector<std::shared_ptr<IBestiole>> detectedNeighbors)=0;
	virtual bool doClone()=0;
   	virtual void move( int xLim, int yLim )=0;
   	virtual void draw( UImg & support )=0;
	virtual int getID() const = 0;
	virtual double getSpeed() = 0;
	virtual double getDirection() = 0;
	virtual std::pair<int,int> getPos() = 0;
	virtual int getX() const = 0;
	virtual int getY() const = 0;
	virtual double getSize() const = 0;
	virtual double getDeathRate() const = 0;
};

#endif