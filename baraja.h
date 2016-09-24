#pragma once
#include "carta.h"
#include <vector>
using std::vector;
class baraja
{
private:
	vector<carta*> cartas;
public:
	baraja();
	~baraja();
	carta* getCarta(int);
};