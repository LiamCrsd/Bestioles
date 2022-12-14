#include "Shell.h"

Shell::Shell(double resistance, double slow) {
    resistanceFactor = resistance;
    slowFactor = slow; 
}

double Shell::getSpeedFactor() {
    return 1/slowFactor;
}

double Shell::getResistanceFactor() {
    return resistanceFactor;
}