all:	main

main: main.o DonkeyKongGame.o Mario.o Object.o Floor.o Peach.o DonkeyKong.o
	g++ -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf main.o DonkeyKongGame.o Mario.o Object.o Floor.o Peach.o DonkeyKong.o -o main

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

Peach.o: Peach.cpp
	g++ -c Peach.cpp

DonkeyKong.o: DonkeyKong.cpp
	g++ -c DonkeyKong.cpp

clean:
	rm -f *.o main
