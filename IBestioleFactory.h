#ifndef IBESTIOLEFACTORY_H
#define IBESTIOLEFACTORY_H
#include "Bestiole.h"
#include <memory>
class IBestioleFactory{
    public:
	    virtual ~IBestioleFactory() {};
        
        virtual std::shared_ptr<IBestiole> createBestiole()=0;
        virtual std::shared_ptr<IBestiole> createBestiole(std::shared_ptr<IBestiole> bestiole)=0;
        virtual std::shared_ptr<IBestiole> createBestiole(int type)=0;
};
#endif