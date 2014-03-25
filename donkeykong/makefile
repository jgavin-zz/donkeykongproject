all:	main

main: main.o DonkeyKongGame.o Mario.o Object.o
	g++ -lSDL  main.o DonkeyKongGame.o Mario.o Object.o -o main

main.o: main.cpp
	g++ -c main.cpp

DonkeyKongGame.o:  DonkeyKongGame.cpp
	g++ -c DonkeyKongGame.cpp

Object.o: Object.cpp
	g++ -c Object.cpp

Mario.o:   Mario.cpp
	g++ -c Mario.cpp

clean:
	rm -f *.o main
