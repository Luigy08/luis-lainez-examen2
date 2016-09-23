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
	string nombreLog;
	int idLog;
	cout<<"=====LOGIN====="<<endl;
	cout<<"Nombre: ";
	cin>>nombreLog;
	cout<<"ID: ";
	cin>>idLog;
	cout<<"==============="<<endl;
	
	for (int i = 0; i < listaPersonas.size(); i++)
	{
		if (nombreLog==listaPersonas[i]->getNombre() && idLog==listaPersonas[i]->getId())
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
			int op=0;
			cout<<"1.-Agregar"<<endl<<"2.-Modificar"<<endl<<"3.-Eliminar"<<endl<<"...";
			cin>>op;
			switch(op){
				case 1:{
					int opAdd=0;
					cout<<"1.-Jugador"<<endl<<"2.-Repartidor"<<endl<<"3.-Mesas"<<endl<<"...";
					cin>>opAdd;
					switch(opAdd){
						case 1:{
							string nombre;
							int edad,id;

							string lugar,nickName;
							int dinero;
							cout<<"Nombre: ";
							cin>>nombre;
							cout<<"Edad: ";
							cin>>edad;
							cout<<"ID: ";
							cin>>id;
							listaPersonas.push_back(new jugador(nombre,edad,id,lugar,nickName,dinero));
							break;
						}
						case 2:{
							string nombre;
							int edad,id;
							cout<<"\tDificultad"<<endl;
							cout<<"1.-Dificil"<<"\t"<<"2.-Intermedio"<<"\t"<<"3.-Facil"<<endl<<"...";
							int opDificultad,dinero;
							cin>>opDificultad;
							string dificultad="";
							if (opDificultad==1)
							{
								dificultad="Dificil";
							}else if (opDificultad==2)
							{
								dificultad="Intermedio";
							}else if (opDificultad==3)
							{
								dificultad="Facil";
							}
							cout<<"Dinero: ";
							cin>>dinero;
							baraja _baraja;
							listaPersonas.push_back(new repartidor(nombre,edad,id,dificultad,dinero,_baraja));

							break;
						}
						case 3:{
							int conR=0,conJ=0;
							for (int i = 0; i < listaPersonas.size(); i++)
							{
								if (dynamic_cast<jugador*>(listaPersonas[i]))
								{
									conJ++;
								}
								if (dynamic_cast<repartidor*>(listaPersonas[i]))
								{
									conR++;
								}
							}
							if (conR>0&&conJ>0)
							{
								int numero,opTipo,opR,opJ;
								string tipo;
								repartidor* _repartidor;
								jugador* _jugador;
								cout<<"Numero de mesa: ";
								cin>>numero;
								cout<<"\tTipo"<<endl;;
								cout<<"1.-VIP"<<"\t"<<"2.-Clasica"<<"\t"<<"3.-Viajero"<<endl;
								cin>>opTipo;
								if (opTipo==1)
								{
									tipo="VIP";
								}else if (opTipo==2)
								{
									tipo="Clasica";
								}else if (opTipo==3)
								{
									tipo="Viajero";
								}
								
								cout<<"\tRepartidores"<<endl;
								for (int i = 0; i < listaPersonas.size(); i++)
								{
									if (dynamic_cast<repartidor*>(listaPersonas[i]))
									{
										cout<<i<<".-"<<dynamic_cast<repartidor*>(listaPersonas[i])->toString()<<endl;	
									}
								}
								cout<<"...";
								cin>>opR;
								opR--;
								_repartidor=dynamic_cast<repartidor*>(listaPersonas[opR]);

								cout<<"\tJugadores"<<endl;
								for (int i = 0; i < listaPersonas.size(); i++)
								{
									if (dynamic_cast<jugador*>(listaPersonas[i]))
									{
										cout<<i<<".-"<<dynamic_cast<jugador*>(listaPersonas[i])->toString()<<endl;	
									}
								}
								cout<<"...";
								cin>>opJ;
								opJ--;
								_jugador=dynamic_cast<jugador*>(listaPersonas[opJ]);
								listaMesas.push_back(new mesa(numero,tipo,_repartidor,_jugador));
							}
							break;
						}//fin de mesas
					}
					break;
				}
				case 2:{
					cout<<"-----MODIFICAR-----"<<endl;
					cout<<"Mesas: "<<endl;
					for (int i = 0; i < listaMesas.size(); i++)
					{
						cout<<i<<".-"<<listaMesas[i]->toString()<<endl;
					}
					int opM;
					cout<<"...";
					cin>>opM;
					opM--;

					int numero,opTipo,opR,opJ;
					string tipo;
					repartidor* _repartidor;
					jugador* _jugador;
					cout<<"Numero de mesa: ";
					cin>>numero;
					cout<<"\tTipo"<<endl;;
					cout<<"1.-VIP"<<"\t"<<"2.-Clasica"<<"\t"<<"3.-Viajero"<<endl;
					cin>>opTipo;
					if (opTipo==1)
					{
						tipo="VIP";
					}else if (opTipo==2)
					{
						tipo="Clasica";
					}else if (opTipo==3)
					{
						tipo="Viajero";
					}
					
					cout<<"\tRepartidores"<<endl;
					for (int i = 0; i < listaPersonas.size(); i++)
					{
						if (dynamic_cast<repartidor*>(listaPersonas[i]))
						{
							cout<<i<<".-"<<dynamic_cast<repartidor*>(listaPersonas[i])->toString()<<endl;	
						}
					}
					cout<<"...";
					cin>>opR;
					opR--;
					_repartidor=dynamic_cast<repartidor*>(listaPersonas[opR]);
					cout<<"\tJugadores"<<endl;
					for (int i = 0; i < listaPersonas.size(); i++)
					{
						if (dynamic_cast<jugador*>(listaPersonas[i]))
						{
							cout<<i<<".-"<<dynamic_cast<jugador*>(listaPersonas[i])->toString()<<endl;	
						}
					}
					cout<<"...";
					cin>>opJ;
					opJ--;
					_jugador=dynamic_cast<jugador*>(listaPersonas[opJ]);
					mesa* tem= new mesa(numero,tipo,_repartidor,_jugador);
					listaMesas[opM]=tem;
					break;
				}
				case 3{

					break;
				}
			}//fin del swtich admin
			break;
		}
	}//fin del swtich principal
	return 0;
}