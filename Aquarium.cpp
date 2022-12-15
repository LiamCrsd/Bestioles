#include "Aquarium.h"

#include "Ecosystem.h"
#include "Config.h"
#include "ExternalActionner.h"

#include <chrono>
#include <thread>

Aquarium::Aquarium( int _delay ) : CImgDisplay(), delay( _delay )
{

   int         screenWidth = screen_width();
   int         screenHeight = screen_height();

   Config& config = Config::GetInstance();
   int width = config.width;
   int height = config.height;
   

   cout << "const Aquarium" << endl;


   flotte = new Ecosystem( width, height );
   assign( *flotte, "Simulation d'ecosysteme" );

   this->extActionner = ExternalActionner(this->flotte);

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );

}


Aquarium::~Aquarium( void )
{

   delete flotte;

   cout << "dest Aquarium" << endl;

}


void Aquarium::run( void )
{

   cout << "running Aquarium" << endl;

   while ( ! is_closed() )
   {

      // cout << "iteration de la simulation" << endl;

      if ( is_key() ) {
         cout << "Vous avez presse la touche " << static_cast<unsigned char>( key() );
         cout << " (" << key() << ")" << endl;
         if ( is_keyESC() ) close();
         extActionner.redirectKey(key());
         this_thread::sleep_for(chrono::milliseconds(200));
      }

      flotte->step();
      display( *flotte );

      wait( delay );

   } // while

   extActionner.getReport();

}
