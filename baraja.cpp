#include "carta.h"
#include "baraja.h"
baraja::baraja(){
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j < 14; j++)
		{
			if (i==0)
			{
				cartas.push_back(new carta(j,"♥","Rojo"));
			}
			if (i==1)
			{
				cartas.push_back(new carta(j,"♦","Rojo"));
			}
			if (i==2)
			{
				cartas.push_back(new carta(j,"♠","Negro"));
			}
			if (i==3)
			{
				cartas.push_back(new carta(j,"♣","Negro"));
			}
		}
	}
}
baraja::~baraja(){

}
