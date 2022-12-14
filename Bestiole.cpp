#include "Bestiole.h"
#include "Ecosystem.h"

#include "Gregarious.h"
#include "Fearful.h"
#include "Kamikaze.h"
#include "Farsighted.h"
#include "MultiplePersonnality.h"
#include <cstdlib>
#include <cmath>


const double      Bestiole::LIMITE_VUE = 30.;

int               Bestiole::next = 0;


Bestiole::Bestiole( void ) : Bestiole(0, 0, 0, 0, 0 ,0, 0, 0,rand()%5,std::vector<std::shared_ptr<Sensor>>()) {

   cout << "const Bestiole by default" << endl;
   direction = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   currentSpeed = static_cast<double>( rand() )/RAND_MAX*10.;
   initialSpeed = currentSpeed;
   size = 8.;

}

Bestiole::Bestiole(
   int startX,
   int startY,
   double startDir,
   double startSpeed,
   double size,
   int ageLim,
   double cloneRate,
   double deathRate,
   int behaviorIndex,
   std::vector<std::shared_ptr<Sensor>> sensors
   ) : 
   x(startX), 
   y(startY), 
   direction(startDir),
   currentSpeed(startSpeed),
   initialSpeed(startSpeed),
   size(size),
   ageLim(ageLim),
   cloneRate(cloneRate),
   deathRate(deathRate),
   sensors(sensors)
{

   id = ++next;

   cout << "const Bestiole (" << id << ") of size " << size << endl;

   age = 0;
   dead = false;

   cumulX = cumulY = 0.;
   couleur = new T[ 3 ];
   if (behaviorIndex==0){
        behavior = std::shared_ptr<Behavior>(new Gregarious());
        couleur[0]=0;
        couleur[1]=255;
        couleur[2]=0;
    }
   else if (behaviorIndex==1){
        behavior = shared_ptr<Behavior>(new Fearful());
        couleur[0]=255;
        couleur[1]=0;
        couleur[2]=255;
    }
    else if (behaviorIndex==2){
        behavior = shared_ptr<Behavior>(new Kamikaze());
        couleur[0]=255;
        couleur[1]=0;
        couleur[2]=0;
    }
    else if (behaviorIndex==3){
        behavior = shared_ptr<Behavior>(new Farsighted());
        couleur[0]=0;
        couleur[1]=0;
        couleur[2]=255;
    }
    else{
      behavior = shared_ptr<Behavior>(new MultiplePersonnality());
      couleur[0]=0;
      couleur[1]=0;
      couleur[2]=0;
    }
}


Bestiole::Bestiole( const Bestiole & b )
{

   id = ++next;

   cout << "const Bestiole (" << id << ") par copie" << endl;

   x = b.x;
   y = b.y;
   direction = b.direction;
   currentSpeed = b.currentSpeed;
   initialSpeed = b.initialSpeed;
   size = b.size;
   ageLim = b.ageLim;
   cloneRate = b.cloneRate;
   deathRate = b.deathRate;

   age = b.age;
   dead = b.dead;

   cumulX = cumulY = 0.;
   couleur = new T[ 3 ];
   memcpy( couleur, b.couleur, 3*sizeof(T) );
   sensors = b.sensors;
}


Bestiole::~Bestiole( void )
{

   delete[] couleur;

   cout << "dest Bestiole " << id << endl;

}


void Bestiole::move( int xLim, int yLim )
{

   double         nx, ny;
   double         dx = cos( direction )*currentSpeed;
   double         dy = -sin( direction )*currentSpeed;
   int            cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      direction = fmod(M_PI - direction,2*M_PI);
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      direction = fmod(-direction,2*M_PI);
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }
   currentSpeed = initialSpeed;
}


void Bestiole::draw( UImg & support )
{

   double         xt = x + cos( direction )*size/2.1;
   double         yt = y - sin( direction )*size/2.1;


   support.draw_ellipse( x, y, size, size/5., -direction/M_PI*180., couleur );
   support.draw_circle( xt, yt, size/2., couleur );

}

int Bestiole::getID() const {
   return id;
}

int Bestiole::getX() const {
   return x;
}

int Bestiole::getY() const {
   return y;
}

double Bestiole::getDirection() const {
   return direction;
}

double Bestiole::getSize() const {
   return size;
}

double Bestiole::getDeathRate() const {
   return deathRate;
}


bool Bestiole::iSeeU( const IBestiole & b ) const
{
   for (std::vector<std::shared_ptr<Sensor>>::const_iterator it = sensors.begin() ; it != sensors.end() ; ++it) {
      if ((*it)->isDetected(Bestiole::x, Bestiole::y, Bestiole::direction,
                            b.getX(), b.getY(), 0)) {return true;} //TODO : put real camoo value instead of the "0"
   }
   return false;
}

bool Bestiole::isDead() const { return dead; };
void Bestiole::setDead(bool isDead) {
   cout << "Bestiole " << id << " is dead by collision" << endl;
   dead = isDead;
};

bool Bestiole::atBorder() { throw std::invalid_argument("Not implemented");};
void Bestiole::resolveCollision() {
   direction = fmod(direction - M_PI, 2*M_PI);
};
void Bestiole::resolveDetections(std::vector<std::shared_ptr<IBestiole>> detectedNeighbors){
   currentSpeed = behavior->calcSpeed(x,y,initialSpeed,direction,detectedNeighbors);
   direction = behavior->calcDirection(x,y,initialSpeed,direction,detectedNeighbors);
   
}; 
bool Bestiole::doClone() { throw std::invalid_argument("Not implemented");};

void Bestiole::grow_old() {
  age += 1;
  if (age >= ageLim) {
    //cout << "Bestiole " << id << " is dead by old" << endl;
    dead = true;
  }
}
