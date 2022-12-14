#ifndef _FINS_H_
#define _FINS_H_

#include "Accessory.h"

class Fins : public Accessory
{
private:
    double speedFactor;
public:
    Fins(double speedFactor);
    double getSpeedFactor();
};
#endif