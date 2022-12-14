#ifndef _SHELL_H_
#define _SHELL_H_

#include "Accessory.h"

class Shell : public Accessory
{
private:
    double resistanceFactor;
    double slowFactor;
public:
    Shell(double ressistanceFactor, double slowFactor);
    double getSpeedFactor();
    double getResistanceFactor();
};
#endif