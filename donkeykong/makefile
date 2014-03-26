all:	main

main: main.o DonkeyKongGame.o Mario.o Object.o Floor.o
	g++ -lSDL  main.o DonkeyKongGame.o Mario.o Object.o Floor.o -o main

main.o: main.cpp
	g++ -c main.cpp

DonkeyKongGame.o:  DonkeyKongGame.cpp
	g++ -c DonkeyKongGame.cpp

Object.o: Object.cpp
	g++ -c Object.cpp

Mario.o:   Mario.cpp
	g++ -c Mario.cpp

Floor.o: Floor.cpp
	g++ -c Floor.cpp

clean:
	rm -f *.o main
