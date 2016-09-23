#include "persona.h"
#include "repartidor.h"
#include <string>
using std::string;
repartidor::repartidor(string nombre,int edad,int id,string dificultad,int dinero,baraja _baraja):persona(nombre,edad,id),
dificultad(dificultad),dinero(dinero),_baraja(_baraja){

}
repartidor::~repartidor(){

}
repartidor::repartidor(){
	
}