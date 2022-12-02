main : main.cpp Aquarium.o Bestiole.o Ecosystem.o BestioleFactory.o CollectionBestiole.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Ecosystem.o BestioleFactory.o CollectionBestiole.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp IBestiole.h
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Ecosystem.o : Ecosystem.h Ecosystem.cpp
	g++ -Wall -std=c++11  -c Ecosystem.cpp -I .

BestioleFactory.o : BestioleFactory.h BestioleFactory.cpp
	g++ -Wall -std=c++11  -c BestioleFactory.cpp -I .

CollectionBestiole.o : CollectionBestiole.h CollectionBestiole.cpp
	g++ -Wall -std=c++11  -c CollectionBestiole.cpp -I .

Gregarious.o : Gregarious.h Gregarious.cpp Behavior.h IBestiole.h
	g++ -Wall -std=c++11 -c Gregarious.cpp -I .

Fearful.o : Fearful.h Fearful.cpp Config.h Behavior.h IBestiole.h
	g++ -Wall -std=c++11 -c Fearful.cpp -I .

Kamikaze.o : Kamikaze.h Kamikaze.cpp Behavior.h IBestiole.h
	g++ -Wall -std=c++11 -c Kamikaze.cpp -I

MultiplePersonnality.o : MultiplePersonnality.h MultiplePersonnality.cpp Behavior.h IBestiole.h Gregarious.h Fearful.h Kamikaze.h Farsighted.h Config.h
	g++ -Wall -std=c++11 -c MultiplePersonnality.cpp -I
Behavior.o : behavior.h behavior.cpp IBestiole.h
	g++ -Wall -std=c++11 -c Behavior.cpp -I

clean:
	rm -rf *.o main

