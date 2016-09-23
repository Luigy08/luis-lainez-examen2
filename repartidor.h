#pragma once
#include "persona.h"
#include "baraja.h"
#include <string>
using std::string;
class repartidor:public persona
{
private:
	string dificultad;
	int dinero;
	baraja _baraja;
public:
	repartidor();
	repartidor(string,int,int,string,int,baraja);
	~repartidor();
	
};