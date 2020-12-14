   
   
/*
	Name: PROYECTO TIENDA
	Copyright: 
	Author: MIGUEL ANGEL BAÑOL CIFUENTES, DAVID DUQUE VELEZ
	Date: 13/12/20 20:33
	Description: Se desarrolla un proyecto para una tienda básica con operaciones báscias
*/
   
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void mostrarempleados();
void contratarempleados();
void despedirempleados();
void buscarempleados();

class Cola
{
	private:
		string empleado;
		Cola *siguiente;
		*primero, *cola, *ultimo;
 	public:
 		Cola();
 		void mostrarempleados();
		void contratarempleados();
		void despedirempleados();
		void buscarempleados();
		~Cola();
};

Cola::Cola()
{
	empleado = " ";
	primero = NULL;
	ultimo = NULL;
	siguiente = NULL;
	cola = NULL;
}


void Cola::contratarempleados()
{
	Cola *nuevo = new Cola();
	cout << "Ingrese el nombre del empleado" <<endl;
	cin >> nuevo -> empleado;
	
	if(ultimo != NULL)
	{
		ultimo -> siguiente = cola;
		nuevo -> siguiente = NULL;
		ultimo = nuevo;
		cout<<"Empleado contratado! "<<endl;
	
	}
	else{
		primero = ultimo = nuevo;
		cout << "primer empleado contratado"<<endl;
		cout << primero << " " << ultimo << " " << cola << endl;
	}
		cout << ultimo -> siguiente << " " << nuevo -> siguiente << endl;
}
void Cola::mostrarempleados()
{
	if(ultimo == NULL)
	{
		cout << "No hay empleados hoy" << endl;
		return;
	}
	nuevo = primero;
	cout << "Los empleado son " << endl;
	while(nuevo != NULL)
	{
		cout << nuevo -> empleado << endl;
		nuevo = nuevo -> siguiente;

	}
}

void despedirempleados()
{
	if(primero != NULL)
	{
		nuevo = primero;
		cout << "Despedido " << primero -> empleado << endl;
		primero = nuevo -> siguiente;
		delete(nuevo);
		if(primero == NULL)
		{
			nuevo = NULL;
			ultimo = NULL;
		}
	}
	else{
		cout << "No hay empleado" << endl;
	}
}
void Cola::buscarempleados()
{
	if(primero == NULL)
	{
		cout << "No hay empleados" << endl;
		return;
	}
	nuevo = primero;
	bool encontrado = false;
	string buscaremp;
	cout << "Ingrese el empleado a buscar" << endl;
	cin >> buscaremp;
	while(cola != NULL){
		if(buscaremp==nuevo->dato)
		{
			cout << "Encontrado, el empleado es: " << cola->dato << endl;
			encontrado = true;
			break;
		}
		nuevo = nuevo -> siguiente;
	}
	if(encontrado == false)
	{
		cout << "No se encontro el empleado" << endl;
	}

}




