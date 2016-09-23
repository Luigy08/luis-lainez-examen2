#include "persona.h"
#include "administrador.h"
#include <string>
using std::string;
#include <sstream>
using std::string;
using std::stringstream;
administrador::administrador(string nombre,int edad,int id,string experiencia,string rango,int sueldo):persona(nombre,edad,id),
experiencia(experiencia),rango(rango),sueldo(sueldo){

}
administrador::~administrador(){

}
string administrador::toString()const{
	stringstream ss;
	ss<<persona::toString()<<" Experiencia: "<<experiencia<<" Rango: "<<rango<<" Sueldo: "<<sueldo;
	return ss.str();
}
