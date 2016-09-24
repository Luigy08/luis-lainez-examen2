#pragma once
#include <string>
using std::string;
class carta
{
private:
	int valor;
	string simbolo;
	string color;
public:
	carta(int,string,string);
	~carta();
	string toString()const;
};