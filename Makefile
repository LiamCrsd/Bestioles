main : main.cpp Aquarium.o Bestiole.o Ecosystem.o ExternalActionner.o BestioleFactory.o CollectionBestiole.o Accessory.o Fins.o Shell.o Camouflage.o Behavior.o Gregarious.o Fearful.o Kamikaze.o Farsighted.o MultiplePersonnality.o Sensor.o Ears.o Eyes.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Ecosystem.o ExternalActionner.o BestioleFactory.o CollectionBestiole.o Accessory.o Fins.o Shell.o Camouflage.o Behavior.o Gregarious.o Fearful.o Kamikaze.o Farsighted.o MultiplePersonnality.o Sensor.o Ears.o Eyes.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp IBestiole.h behaviors/Behavior.h behaviors/Gregarious.h behaviors/Fearful.h behaviors/Kamikaze.h behaviors/Farsighted.h behaviors/MultiplePersonnality.h
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Ecosystem.o : Ecosystem.h Ecosystem.cpp
	g++ -Wall -std=c++11  -c Ecosystem.cpp -I .

ExternalActionner.o : ExternalActionner.h ExternalActionner.cpp
	g++ -Wall -std=c++11 -c ExternalActionner.cpp -I .

BestioleFactory.o : BestioleFactory.h BestioleFactory.cpp
	g++ -Wall -std=c++11  -c BestioleFactory.cpp -I .

CollectionBestiole.o : CollectionBestiole.h CollectionBestiole.cpp
	g++ -Wall -std=c++11  -c CollectionBestiole.cpp -I .

Behavior.o : behaviors/Behavior.h behaviors/Behavior.cpp IBestiole.h
	g++ -Wall -std=c++11 -c behaviors/Behavior.cpp -I .
Gregarious.o : behaviors/Gregarious.h behaviors/Gregarious.cpp behaviors/Behavior.h IBestiole.h
	g++ -Wall -std=c++11 -c behaviors/Gregarious.cpp -I .
Fearful.o : behaviors/Fearful.h behaviors/Fearful.cpp Config.h behaviors/Behavior.h IBestiole.h
	g++ -Wall -std=c++11 -c behaviors/Fearful.cpp -I .
Farsighted.o : behaviors/Farsighted.h behaviors/Farsighted.cpp Config.h behaviors/Behavior.h IBestiole.h
	g++ -Wall -std=c++11 -c behaviors/Farsighted.cpp -I .
Kamikaze.o : behaviors/Kamikaze.h behaviors/Kamikaze.cpp behaviors/Behavior.h IBestiole.h
	g++ -Wall -std=c++11 -c behaviors/Kamikaze.cpp -I .
MultiplePersonnality.o : behaviors/MultiplePersonnality.h behaviors/MultiplePersonnality.cpp behaviors/Behavior.h IBestiole.h behaviors/Gregarious.h behaviors/Fearful.h behaviors/Kamikaze.h behaviors/Farsighted.h Config.h
	g++ -Wall -std=c++11 -c behaviors/MultiplePersonnality.cpp -I .

Accessory.o : accessories/Accessory.h accessories/Accessory.cpp
	g++ -Wall -std=c++11 -c accessories/Accessory.cpp -I .
Shell.o : accessories/Shell.h accessories/Shell.cpp
	g++ -Wall -std=c++11 -c accessories/Shell.cpp -I .
Fins.o : accessories/Fins.h accessories/Fins.cpp
	g++ -Wall -std=c++11 -c accessories/Fins.cpp -I .
Camouflage.o : accessories/Camouflage.h accessories/Camouflage.cpp
	g++ -Wall -std=c++11 -c accessories/Camouflage.cpp -I .

Sensor.o: sensors/Sensor.h sensors/Sensor.cpp 
	g++ -Wall -std=c++11 -c sensors/Sensor.cpp -I .
Ears.o: sensors/Ears.h sensors/Ears.cpp
	g++ -Wall -std=c++11 -c sensors/Ears.cpp -I .
Eyes.o: sensors/Eyes.h sensors/Eyes.cpp
	g++ -Wall -std=c++11 -c sensors/Eyes.cpp -I .

clean:
	rm -rf *.o main
