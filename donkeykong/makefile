all:	main

main: main.o DonkeyKongGame.o Mario.o
	g++ -lSDL  main.o DonkeyKongGame.o Mario.o -o main

main.o: main.cpp
	g++ -c main.cpp

DonkeyKongGame.o:  DonkeyKongGame.cpp
	g++ -c DonkeyKongGame.cpp

Mario.o:   Mario.cpp
	g++ -c Mario.cpp

clean:
	rm -f *.o main
