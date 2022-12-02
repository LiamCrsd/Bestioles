main : main.cpp Aquarium.o Bestiole.o Milieu.o accessories/Accessory.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

accessories/Accessory.o : accessories/Accessory.h accessories/Accessory.cpp accessories/Shell.o accessories/Fins.o accessories/Camouflage.o
	g++ -Wall -std=c++11 -c accessories/Accessory.cpp -I .
accessories/Shell.o : accessories/Shell.h accessories/Shell.cpp
	g++ -Wall -std=c++11 -c accessories/Shell.cpp -I .
accessories/Fins.o : accessories/Fins.h accessories/Fins.cpp
	g++ -Wall -std=c++11 -c accessories/Fins.cpp -I .
accessories/Camouflage.o : accessories/Camouflage.h accessories/Camouflage.cpp
	g++ -Wall -std=c++11 -c accessories/Camouflage.cpp -I .
clean:
	rm -rf *.o main

