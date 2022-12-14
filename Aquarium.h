#ifndef _AQUARIUM_H_
#define _AQUARIUM_H_


#include <iostream>
#include <CImg.h>

using namespace std;
using namespace cimg_library;

#include "ExternalActionner.h"
class Ecosystem;


class Aquarium : public CImgDisplay
{

private :
   Ecosystem       * flotte;
   ExternalActionner extActionner;
   int            delay;

public :
   Aquarium( int _delay );
   ~Aquarium( void );

   Ecosystem & getEcosystem( void ) { return *flotte; }

   void run( void );

};


#endif
