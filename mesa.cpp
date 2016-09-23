#include "repartidor.h"

#include "jugador.h"
#include "mesa.h"
#include <string>
using std::string;
#include <sstream>
using std::string;
using std::stringstream;
mesa::mesa(int numero, string tipo,repartidor* _repartidor,jugador* _jugador){
	this->numero=numero;
	this->tipo=tipo;
	this->_repartidor=_repartidor;
	this->_jugador=_jugador;
}
mesa::~mesa(){

}
string mesa::toString()const{
	stringstream ss;
	ss<<"Numero: "<<numero<<" Tipo: "<<tipo<<"Repartidor: "<<_repartidor->getNombre()<<" Jugador: "<<_jugador->getNombre();
	return ss.str();
}