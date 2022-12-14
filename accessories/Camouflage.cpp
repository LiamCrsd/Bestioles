#include "Camouflage.h"

Camouflage::Camouflage(double camouflage) {
    camouflageFactor = camouflage;
}

double Camouflage::getCamouflageFactor() {
    return camouflageFactor;
}