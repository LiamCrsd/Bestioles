#include "Aquarium.h"
#include "Ecosystem.h"
#include "Bestiole.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium aquarium( 640, 480, 30 );

   for ( int i = 1; i <= 20; ++i )
      aquarium.getEcosystem().birthBestiole();
   aquarium.run();


   return 0;

}
