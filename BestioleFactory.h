#ifndef BESTIOLE_FACTORY_H
#define BESTIOLE_FACTORY_H
#include "IBestioleFactory.h"
#include <memory>
class BestioleFactory: public IBestioleFactory{
    private:
        virtual void setCoordinates(Bestiole& bestiole);

    public:
        virtual std::shared_ptr<IBestiole> createBestiole();
        virtual std::shared_ptr<IBestiole> createBestiole(std::shared_ptr<IBestiole> bestiole);
        virtual std::shared_ptr<IBestiole> createBestiole(int type);
};
#endif