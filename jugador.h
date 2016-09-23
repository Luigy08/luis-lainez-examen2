#pragma once
#include "persona.h"
#include <string>
using std::string;
class jugador:public persona
{
private:
	string lugar;
	string nickName;
	int dinero;
public:
	jugador(string,int,int,string,string,int);
	virtual~jugador();
	virtual string toString()const;
	jugador();
};