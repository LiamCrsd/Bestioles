#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_


#include <iostream>
#include <CImg.h>

using namespace std;
using namespace cimg_library;


class Ecosystem;


class Aquarium : public CImgDisplay
{

private :
   Ecosystem       * flotte;

   int            delay;

public :
   Aquarium( int width, int height, int _delay );
   ~Aquarium( void );

   Ecosystem & getEcosystem( void ) { return *flotte; }

   void run( void );

};


#endif
