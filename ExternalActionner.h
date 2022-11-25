#ifndef _EXTERNALACTIONNER_H_
#define _EXTERNALACTIONNER_H_

class Aquarium;
class BestioleFactory;
class ConcreteBestiole;

class ExternalActionner 
{
private:
    Aquarium  *aquarium;
    BestioleFactory *factory;
public:
    ExternalActionner();

    void createBestiole( void );
    void createBestiole( int );

    void killBestiole();
    void killBestiole(int);
    void getReport();
};
#endif