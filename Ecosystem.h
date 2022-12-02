#ifndef _ECOSYS_H_
#define _ECOSYS_H_


#include "UImg.h"
#include "Bestiole.h"
#include "BestioleFactory.h"
#include "CollectionBestiole.h"
#include "Config.h"

#include <iostream>
#include <vector>

using namespace std;


class Ecosystem : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   BestioleFactory bestioleFactory;
   CollectionBestiole collectionBestiole;


public :
   Ecosystem( int _width, int _height );
   ~Ecosystem( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   void birthBestiole();
   void cloneBestiole(const Bestiole& bestiole);
   int nbVoisins( const Bestiole & b );

};


#endif
