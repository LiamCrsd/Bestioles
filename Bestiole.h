#ifndef _BESTIOLE_H_
#define _BESTIOLE_H_

#include <vector>
#include "IBestiole.h"
#include "UImg.h"
#include <iostream>
#include "accessories/Accessory.h"
#include "sensors/Sensor.h"


using namespace std;

class Ecosystem;


class Bestiole : public IBestiole
{

private :
   static const double     LIMITE_VUE;
   static int              next;

private :
   int               id;
   int               x, y;
   double            direction;
   double            speed;
   double            size;
   int               ageLim;
   double            cloneRate;
   double            deathRate;
   std::vector<std::shared_ptr<Sensor>> sensors;
   std::vector<std::shared_ptr<Accessory>> accessories;
   int               age;
   bool              dead;

   double            cumulX, cumulY;
   T               * couleur;


public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole(   
      int startX,
      int startY,                                    // Constructor of factory      int x, int y,
      double direction,
      double speed,
      double size,
      int ageLim,
      double cloneRate,
      double deathRate,
      std::vector<std::shared_ptr<Sensor>> sensors,
      std::vector<std::shared_ptr<Accessory>> accessories
   );
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   ~Bestiole( void );                              // Destructeur

   bool isDead() const;
   void setDead(bool isDead);

	bool atBorder();
	void resolveCollision();
	void resolveDetections(std::vector<std::shared_ptr<IBestiole>> detectedNeighbors);
	bool doClone();
   void move( int xLim, int yLim ); 
   void draw( UImg & support );

   bool iSeeU( const IBestiole & b ) const;
   int getID() const;
   int getX() const;
	int getY() const;
   double getDirection() const;
	double getSize() const;
	double getDeathRate() const;
   void grow_old();
   double getCurrentSpeed() const;
   double getCamouflage() const;
};

#endif
