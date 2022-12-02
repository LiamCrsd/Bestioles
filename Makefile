<<<<<<< HEAD
main : main.cpp Aquarium.o Bestiole.o Ecosystem.o BestioleFactory.o CollectionBestiole.o Behavior.o Gregarious.o Fearful.o Kamikaze.o Farsighted.o MultiplePersonnality.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Ecosystem.o BestioleFactory.o CollectionBestiole.o Behavior.o Gregarious.o Fearful.o Kamikaze.o Farsighted.o MultiplePersonnality.o -I . -lX11 -lpthread
=======
main : main.cpp Aquarium.o Bestiole.o Ecosystem.o BestioleFactory.o CollectionBestiole.o Sensor.o Ears.o Eyes.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Ecosystem.o BestioleFactory.o CollectionBestiole.o Sensor.o Ears.o Eyes.o -I . -lX11 -lpthread
>>>>>>> 528302fcb1b6bec4419bd24ba3f36b9322ce0ce9

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp IBestiole.h Behavior.h Gregarious.h Fearful.h Kamikaze.h Farsighted.h MultiplePersonnality.h
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Ecosystem.o : Ecosystem.h Ecosystem.cpp
	g++ -Wall -std=c++11  -c Ecosystem.cpp -I .

BestioleFactory.o : BestioleFactory.h BestioleFactory.cpp
	g++ -Wall -std=c++11  -c BestioleFactory.cpp -I .

CollectionBestiole.o : CollectionBestiole.h CollectionBestiole.cpp
	g++ -Wall -std=c++11  -c CollectionBestiole.cpp -I .

<<<<<<< HEAD
Behavior.o : Behavior.h Behavior.cpp IBestiole.h
	g++ -Wall -std=c++11 -c Behavior.cpp -I .

Gregarious.o : Gregarious.h Gregarious.cpp Behavior.h IBestiole.h
	g++ -Wall -std=c++11 -c Gregarious.cpp -I .

Fearful.o : Fearful.h Fearful.cpp Config.h Behavior.h IBestiole.h
	g++ -Wall -std=c++11 -c Fearful.cpp -I .

Kamikaze.o : Kamikaze.h Kamikaze.cpp Behavior.h IBestiole.h
	g++ -Wall -std=c++11 -c Kamikaze.cpp -I .

MultiplePersonnality.o : MultiplePersonnality.h MultiplePersonnality.cpp Behavior.h IBestiole.h Gregarious.h Fearful.h Kamikaze.h Farsighted.h Config.h
	g++ -Wall -std=c++11 -c MultiplePersonnality.cpp -I .

=======
Sensor.o: sensors/Sensor.h sensors/Sensor.cpp 
	g++ -Wall -std=c++11 -c sensors/Sensor.cpp -I .

Ears.o: sensors/Ears.h sensors/Ears.cpp
	g++ -Wall -std=c++11 -c sensors/Ears.cpp -I .

Eyes.o: sensors/Eyes.h sensors/Eyes.cpp
	g++ -Wall -std=c++11 -c sensors/Eyes.cpp -I .
>>>>>>> 528302fcb1b6bec4419bd24ba3f36b9322ce0ce9

clean:
	rm -rf *.o main
