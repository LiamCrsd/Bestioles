main : main.cpp Aquarium.o Bestiole.o Ecosystem.o BestioleFactory.o CollectionBestiole.o Sensor.o Ears.o Eyes.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Ecosystem.o BestioleFactory.o CollectionBestiole.o Sensor.o Ears.o Eyes.o -I . -lX11 -lpthread

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

Sensor.o: sensors/Sensor.h sensors/Sensor.cpp 
	g++ -Wall -std=c++11 -c sensors/Sensor.cpp -I .

Ears.o: sensors/Ears.h sensors/Ears.cpp
	g++ -Wall -std=c++11 -c sensors/Ears.cpp -I .

Eyes.o: sensors/Eyes.h sensors/Eyes.cpp
	g++ -Wall -std=c++11 -c sensors/Eyes.cpp -I .

clean:
	rm -rf *.o main
