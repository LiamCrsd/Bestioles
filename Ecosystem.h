#ifndef _ECOSYS_H_
#define _ECOSYS_H_


#include "UImg.h"
#include "Bestiole.h"

#include <iostream>
#include <vector>

using namespace std;


class Ecosystem : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<Bestiole>   listeBestioles;

public :
   Ecosystem( int _width, int _height );
   ~Ecosystem( void );

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   void addMember( const Bestiole & b ) { listeBestioles.push_back(b); listeBestioles.back(); }
   int nbVoisins( const Bestiole & b );

};


#endif
