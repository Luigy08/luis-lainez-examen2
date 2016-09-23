#pragma once
#include "persona.h"
#include <string>
using std::string;
class administrador:public persona
{
private:
	string experiencia;
	string rango;
	int sueldo;
public:
	administrador(string,int,int,string,string,int);
	virtual~administrador();
	virtual string toString()const;	
};