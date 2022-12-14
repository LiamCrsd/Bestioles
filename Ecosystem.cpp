#include "Ecosystem.h"
#include "BestioleFactory.h"
#include "CollectionBestiole.h"
#include "IBestiole.h"
#include "Config.h"

#include <cstdlib>
#include <ctime>


const T    Ecosystem::white[] = { (T)255, (T)255, (T)255 };


Ecosystem::Ecosystem( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Ecosystem" << endl;

   std::srand( time(NULL) );

}


Ecosystem::~Ecosystem( void )
{

   cout << "dest Ecosystem" << endl;

}

void Ecosystem::birthBestiole() {
   std::shared_ptr<IBestiole> newBestiole = bestioleFactory.createBestiole();
   collectionBestiole.addBestiole(newBestiole);
}

void Ecosystem::cloneBestiole(std::shared_ptr<IBestiole> bestiole) {
   std::shared_ptr<IBestiole> clonedBestiole = bestioleFactory.createBestiole(bestiole);
   collectionBestiole.addBestiole(clonedBestiole);
}


void Ecosystem::step( void )
{
   Config& config = Config::GetInstance();
   std::vector<std::shared_ptr<IBestiole>> listeBestioles = collectionBestiole.getBestiolesList();

   double birthRoll = static_cast<double>( std::rand() )/RAND_MAX;
   if (birthRoll < config.birthRate) {
      //cout << "Birthing new bestiole randomly" << endl;
      birthBestiole();
   }
   collectionBestiole.processDetections();
   collectionBestiole.processCollisions();

   collectionBestiole.processOld();

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<std::shared_ptr<IBestiole>>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      if ( (*it)->doClone() ) {
         cloneBestiole(*it);
      }
   }


   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<std::shared_ptr<IBestiole>>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {
      (*it)->move( this->getWidth(), this->getHeight() );
      (*it)->draw( *this );

   } // for

   //Gestion des morts
   collectionBestiole.processDead();

}
