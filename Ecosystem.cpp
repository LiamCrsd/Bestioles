#include "Ecosystem.h"

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


void Ecosystem::step( void )
{

   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {

      it->action( *this );
      it->draw( *this );

   } // for

}


int Ecosystem::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::vector<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}
