#include "carta.h"
#include <string>
using std::string;
#include <sstream>
using std::string;
using std::stringstream;
carta::carta(int valor,string simbolo,string color){
	this->valor=valor;
	this->simbolo=simbolo;
	this->color=color;
}
carta::~carta(){

}
string carta::toString()const{
	stringstream ss;
	ss<<"Valor: "<<valor<<" Simbolo: "<<simbolo<<" Color: "<<color;
	return ss.str();
}