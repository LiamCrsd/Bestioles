#include "Ecosystem.h"
#include "BestioleFactory.h"
#include "CollectionBestiole.h"
#include "IBestiole.h"

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
   std::shared_ptr<IBestiole> newbestiole = bestioleFactory.createBestiole();
   collectionBestiole.addBestiole(newbestiole);
}


void Ecosystem::step( void )
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   std::vector<std::shared_ptr<IBestiole>> listeBestioles = collectionBestiole.getBestiolesList();
   for ( std::vector<std::shared_ptr<IBestiole>>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {

      (*it)->move( this->getWidth(), this->getHeight() );
      (*it)->draw( *this );

   } // for

}


int Ecosystem::nbVoisins( const Bestiole & b )
{

   int         nb = 0;

   /*std::vector<std::shared_ptr<IBestiole>> listeBestioles = collectionBestiole.getBestiolesList();
   for ( std::vector<std::shared_ptr<IBestiole>>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == **it) && b.jeTeVois(**it) )
         ++nb;

   return nb;*/

}
