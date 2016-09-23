temp: main.o persona.o repartidor.o jugador.o administrador.o carta.o baraja.o mesa.o
	g++ main.o persona.o repartidor.o jugador.o administrador.o carta.o baraja.o mesa.o -o temp
main.o: main.cpp persona.h repartidor.h jugador.h administrador.h carta.h baraja.h mesa.h
	g++ -c main.cpp
persona.o: persona.cpp persona.h
	g++ -c persona.cpp
repartidor.o: repartidor.cpp repartidor.h persona.h
	g++ -c repartidor.cpp
administrador.o: administrador.cpp administrador.h persona.h
	g++ -c administrador.cpp
jugador.o:jugador.cpp jugador.h persona.h
	g++ -c jugador.cpp
carta.o: carta.cpp carta.h
	g++ -c carta.cpp
baraja.o: baraja.cpp baraja.h carta.h
	g++ -c baraja.cpp
mesa.o: mesa.cpp mesa.h jugador.h repartidor.h
	g++ -c mesa.cpp