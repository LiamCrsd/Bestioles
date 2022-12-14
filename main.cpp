#include "Aquarium.h"
#include "Ecosystem.h"
#include "Bestiole.h"

#include <iostream>

using namespace std;


int main()
{
   Aquarium aquarium( 30 );

   for ( int i = 1; i <= 30; ++i )
      aquarium.getEcosystem().birthBestiole();
   aquarium.run();


   return 0;

}
