#include "persona.h"
#include "jugador.h"
#include <string>
using std::string;
#include <sstream>
using std::string;
using std::stringstream;
jugador::jugador(string nombre,int edad,int id,string lugar,string nickName,int dinero):persona(nombre,edad,id),
lugar(lugar),nickName(nickName),dinero(dinero){

}
jugador::~jugador(){

}
jugador::jugador(){

}
string jugador::toString()const{
	stringstream ss;
	ss<<persona::toString()<<" Nick name: "<<nickName<<" Dinero: "<<dinero;
	return ss.str();
}
