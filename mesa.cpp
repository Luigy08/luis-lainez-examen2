#include "repartidor.h"

#include "jugador.h"
#include "mesa.h"
#include <string>
using std::string;
mesa::mesa(int numero, string tipo,repartidor _repartidor,jugador _jugador){
	this->numero=numero;
	this->tipo=tipo;
	this->_repartidor=_repartidor;
	this->_jugador=_jugador;
}
mesa::~mesa(){

}