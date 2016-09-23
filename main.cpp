#include "persona.h"
#include "administrador.h"
#include "repartidor.h"
#include "jugador.h"
#include "carta.h"
#include "baraja.h"
#include "mesa.h"

#include <iostream>
using namespace std;
#include <vector>
using std::vector;
int main(int argc, char const *argv[])
{
	vector<persona*> listaPersonas;
	vector<mesa*> listaMesas;
	persona* login;
	int op=0;
	string nickName;
	int id;
	cout<<"=====LOGIN====="<<endl;
	cout<<"Nick name: ";
	cin>>nickName;
	cout<<"ID: ";
	cin>>id;
	cout<<"==============="<<endl;
	
	for (int i = 0; i < listaPersonas.size(); i++)
	{
		if (nickName==listaPersonas[i]->getNombre() && id==listaPersonas[i]->getId())
			{
				login=listaPersonas[i];
			}	

	}
	int bandera=0;
	if (dynamic_cast<jugador*>(login)!=NULL)
	{
		bandera=2;		
	}
	if (dynamic_cast<administrador*>(login)!=NULL)
	{
		bandera=1;
	}
	switch(bandera){
		case 1:{
			
			break;
		}
	}
	return 0;
}