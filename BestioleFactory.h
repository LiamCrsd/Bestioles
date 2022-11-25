#ifndef BESTIOLE_FACTORY_H
#define BESTIOLE_FACTORY_H
#include "IBestioleFactory.h"
#include <memory>
class BestioleFactory: public IBestioleFactory{
    public:
        virtual std::shared_ptr<Bestiole> createBestiole();
        virtual std::shared_ptr<Bestiole> createBestiole(const Bestiole& bestiole);
        virtual std::shared_ptr<Bestiole> createBestiole(int type);
};
#endif