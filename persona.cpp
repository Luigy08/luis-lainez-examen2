#include "persona.h"
#include <string>
using std::string;
#include <sstream>
using std::string;
using std::stringstream;
persona::persona(string nombre,int edad,int id){
	this->nombre=nombre;
	this->edad=edad;
	this->id=id;
}
string persona::getNombre(){
	return nombre;
}
int persona::getId(){
	return id;
}
persona::persona(){

}
persona::~persona(){

}
string persona::toString()const{
	stringstream ss;
	ss<<nombre<<" Edad: "<<edad<<" ID: "<<id;
	return ss.str();
}
