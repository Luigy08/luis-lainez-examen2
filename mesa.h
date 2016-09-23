#pragma once
#include "repartidor.h"

#include "jugador.h"
#include <string>
using std::string;
class mesa
{
private:
	int numero;
	string tipo;
	repartidor* _repartidor;
	jugador* _jugador;
public:
	mesa(int,string,repartidor*,jugador*);
	~mesa();
	string toString()const;
	
};