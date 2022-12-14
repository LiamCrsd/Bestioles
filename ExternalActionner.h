#ifndef _EXTERNALACTIONNER_H_
#define _EXTERNALACTIONNER_H_


#include "BestioleFactory.h"
#include "CollectionBestiole.h"
#include "Ecosystem.h"
class Behavior;

class ExternalActionner 
{
private:
    BestioleFactory *factory;
    CollectionBestiole  *collectionBestiole;
public:
    ExternalActionner();
    ExternalActionner(Ecosystem*);
    ~ExternalActionner( void );

    void createBestiole( void );
    void createBestiole( int );

    void changeBehavior(int, Behavior);

    void killBestiole();
    void killBestiole(int);
    void getReport();

    void redirectKey(int);
};
#endif