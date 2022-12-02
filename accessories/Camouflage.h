#ifndef _CAMOUFLAGE_H_
#define _CAMOUFLAGE_H_

#include "Accessory.h"

class Camouflage : public Accessory
{
private:
    double camouflageFactor;
public:
    Camouflage(double camouflageFactor);
    double getCamouflageFactor();
};
#endif