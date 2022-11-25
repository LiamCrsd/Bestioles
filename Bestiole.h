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
   int               identite;
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

private :
   void move( int xLim, int yLim );

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
   
   void action( Ecosystem & monMilieu );
   void draw( UImg & support );
   bool isDead();
	bool atBorder();
	void resolveCollision();
	void resolveDetections(std::vector<std::shared_ptr<IBestiole>> detectedNeighbors);
	bool doClone();
	void move();

   bool jeTeVois( const Bestiole & b ) const;

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );
};

#endif