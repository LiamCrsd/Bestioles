#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>

using namespace std;


class Milieu;


class Bestiole
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
   
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );

};


#endif
