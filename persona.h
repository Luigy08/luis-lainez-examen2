#pragma once
#include <string>
using std::string;
class persona
{
private:
	string nombre;
	int edad,id;
public:
	string getNombre();
	int getId();
	persona();
	persona(string,int,int);
	virtual ~persona();
	virtual string toString()const;
};