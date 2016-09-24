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
	listaPersonas.push_back(new administrador("Luis",20,1521,"4","Gerente tiempo completo",40000));
	string nombreLog;
	int idLog;
	bool acceso1=true;
	while(acceso1){
		persona* login=NULL;
		cout<<"=====LOGIN====="<<endl;
		cout<<"Nombre: ";
		cin>>nombreLog;
		cout<<"ID: ";
		cin>>idLog;
		cout<<"==============="<<endl;
		int temporal=0;
		for (int i = 0; i < listaPersonas.size(); i++)
		{
			if (nombreLog==listaPersonas[i]->getNombre() && idLog==listaPersonas[i]->getId())
			{
				temporal=1;
				login=listaPersonas[i];
			}	
		}
		int bandera=3;
		if (temporal==1)
		{
			if (dynamic_cast<jugador*>(login)!=NULL)
			{
				bandera=2;		
			}else if (dynamic_cast<administrador*>(login)!=NULL)
			{
				bandera=1;
			}
		}
		bool acceso=true;
		while(acceso){
			//switch(bandera){
			if(bandera==1){
				int op;
				cout<<"1.-Agregar"<<endl<<"2.-Modificar"<<endl<<"3.-Eliminar"<<endl<<"4.-Salir"<<endl<<"...";
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
											cout<<i+1<<".-"<<dynamic_cast<repartidor*>(listaPersonas[i])->toString()<<endl;	
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
											cout<<i+1<<".-"<<dynamic_cast<jugador*>(listaPersonas[i])->toString()<<endl;	
										}
									}
									cout<<"...";
									cin>>opJ;
									opJ--;
									_jugador=dynamic_cast<jugador*>(listaPersonas[opJ]);
									listaMesas.push_back(new mesa(numero,tipo,_repartidor,_jugador));
								}
								break;
							}//fin mesas agregar
						}
						break;
					}
					case 2:{
						cout<<"-----MODIFICAR-----"<<endl;
						cout<<"Mesas: "<<endl;
						for (int i = 0; i < listaMesas.size(); i++)
						{
							cout<<i+1<<".-"<<listaMesas[i]->toString()<<endl;
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
								cout<<i+1<<".-"<<dynamic_cast<repartidor*>(listaPersonas[i])->toString()<<endl;	
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
								cout<<i+1<<".-"<<dynamic_cast<jugador*>(listaPersonas[i])->toString()<<endl;	
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
					case 3: {
						cout<<"-----ELIMINAR-----"<<endl;
						int opE;
						cout<<"1.-Mesas"<<endl<<"2.-Jugadores"<<endl<<"3.-Repartidores"<<endl<<"...";
						cin>>opE;
						switch(opE){
							case 1:{
								cout<<"Mesas: "<<endl;
								for (int i = 0; i < listaMesas.size(); i++)
								{
									cout<<i+1<<".-"<<listaMesas[i]->toString()<<endl;
								}
								int opM;
								cout<<"...";
								cin>>opM;
								opM--;
								listaMesas.erase(listaMesas.begin()+opM);
								break;
							}
							case 2:{
								cout<<"Jugadores: "<<endl;
								for (int i = 0; i < listaPersonas.size(); i++)
								{
									cout<<i+1<<".-"<<listaPersonas[i]->toString()<<endl;
								}
								int opJ;
								cout<<"...";
								cin>>opJ;
								opJ--;
								listaPersonas.erase(listaPersonas.begin()+opJ);
								break;
							}
							case 3:{
								cout<<"Repartidores: "<<endl;
								for (int i = 0; i < listaPersonas.size(); i++)
								{
									cout<<i+1<<".-"<<listaPersonas[i]->toString()<<endl;
								}
								int opR;
								cout<<"...";
								cin>>opR;
								opR--;
								listaPersonas.erase(listaPersonas.begin()+opR);
								break;
							}
						}
						break;
					}//fin del swtich admin
					case 4:{
						acceso=false;
						break;
					}
					//break;
				}
			}else if(bandera==2){	
					vector<carta> cartas;
					acceso=false;	
			} else if(bandera==3){
					cout<<"Eror intente de nuevo"<<endl;
					acceso=false;		
			}
		}
	}
	for (int i = 0; i < listaPersonas.size(); i++)
	{
		delete listaPersonas[i];
	}
	for (int i = 0; i < listaMesas.size(); i++)
	{
		delete listaMesas[i];
	}
	return 0;
}