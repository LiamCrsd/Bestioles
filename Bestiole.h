#ifndef _BESTIOLE_H_
#define _BESTIOLE_H_

#include "IBestiole.h"
#include "UImg.h"
#include <iostream>


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

   int               age;
   bool              dead;

   double            cumulX, cumulY;
   T               * couleur;

public :                                           // Forme canonique :
   Bestiole( void );                               // Constructeur par defaut
   Bestiole(                                       // Constructor of factory
      int x, int y,
      double direction,
      double speed,
      double size,
      int ageLim,
      double cloneRate,
      double deathRate
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

   bool jeTeVois( const Bestiole & b ) const;
   int getID() const;
   double getSpeed(){return speed;};
   double getDirection(){return direction;};
   std::pair<int,int> getPos(){return std::pair<int,int> (x,y);};
   int getX() const;
	int getY() const;
	double getSize() const;
	double getDeathRate() const;
  void grow_old();
};

#endif
