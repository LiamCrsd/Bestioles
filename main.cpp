#include "Aquarium.h"
#include "Ecosystem.h"
#include "Bestiole.h"

#include <iostream>

using namespace std;


int main()
{
   //init config instance
   Config& config = Config::GetInstance();

   Aquarium aquarium( config.width, config.height, 30 );

   for ( int i = 1; i <= 20; ++i )
      aquarium.getEcosystem().birthBestiole();
   aquarium.run();


   return 0;

}
