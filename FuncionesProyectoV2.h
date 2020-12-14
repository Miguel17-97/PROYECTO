   
   
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

using namespace std;

void mostrarempleados();
void contratarempleados();
void despedirempleados();
void buscarempleados();

class Cola
{
	private:
		string nombre;
		string cedula;
		Cola *sig;
		Cola *primero;
		Cola *ultimo;
 	public:
 		Cola();
 		void contratarEmpleado();
 		void mostrarEmpleado();
 		void buscarEmpleado();
		void despedirEmpleado();
		~Cola();
};

Cola :: Cola()
{
	nombre = " ";
	primero = NULL;
	ultimo = NULL;
	sig = NULL;
}

void Cola :: contratarEmpleado()
{
	Cola *nuevo_empleado = new Cola();
	cout << "\n\t Ingrese el nombre del empleado: ";
	cin >> nuevo_empleado->nombre;

	cout << "\n\t Ingrese la cedula del empleado: ";
	cin >> nuevo_empleado->cedula;
	
	if(primero == NULL)
	{
		primero = nuevo_empleado;
		ultimo = primero;
	}
	else
	{
		ultimo->sig = nuevo_empleado;
		nuevo_empleado->sig = NULL;
		ultimo = nuevo_empleado;
	}
	
	cout << "\n\t Empleado contratado.\t" << endl;
}

void Cola :: mostrarEmpleado()
{
	Cola *recorrer = new Cola();
	recorrer = primero;
	
	if(primero != NULL)
	{
		while(recorrer != NULL)
		{
			fflush(stdin);
			cout << "\n\t   " << recorrer->nombre << " Identificado con C.C: " << recorrer->cedula;
			recorrer = recorrer->sig;
		}
	}
	else
	{
		cout << "\n\t No hay empleados en la lista." << endl;
	}
}

void Cola :: buscarEmpleado()
{
	Cola *recorrer = new Cola();
	recorrer = primero;
	string buscando_e = " ";
	bool encontrado = false;
	
	cout << "\n\t Ingrese el nombre del empleado a buscar: ";
	fflush(stdin);
	cin >> buscando_e;
	fflush(stdin);
	
	if(primero != NULL)
	{
		while(recorrer != NULL && encontrado != true)
		{
			if (recorrer->nombre == buscando_e)
			{
				encontrado = true;
				cout << "\n\t   " << recorrer->nombre << " Identificado con C.C: " << recorrer->cedula;
				fflush(stdin);
			}
			
			recorrer = recorrer->sig;
		}
		
		if(encontrado == false)
		{
			cout << "\n\t No se encuentra el empleado en la lista." << endl;
		}
	}
	else
	{
		cout << "\n\t No hay empleados en la lista." << endl;
	}
}

void Cola :: despedirEmpleado()
{
	Cola *recorrer = new Cola();
	Cola *anterior = new Cola();
	anterior = NULL;
	recorrer = primero;
	string buscando_e = " ";
	bool encontrado = false;
	
	cout << "\n\t Ingrese el nombre del empleado a buscar para despedirlo: ";
	fflush(stdin);
	cin >> buscando_e;
	fflush(stdin);
	
	if(primero != NULL)
	{
		while(recorrer != NULL && encontrado != true)
		{
			if (recorrer->nombre == buscando_e)
			{
				encontrado = true;
				cout << "\n\t   " << recorrer->nombre << " Identificado con C.C: " << recorrer->cedula;
				fflush(stdin);
				
				if (recorrer == primero)
				{
					primero = primero->sig;
				}
				else if (recorrer == ultimo)
				{
					anterior->sig = NULL;
					ultimo = anterior;
				}
				else
				{
					anterior->sig = recorrer->sig;
				}
				
				cout << "\n\t Empleado despedido." << endl;
			}
			
			anterior = recorrer;
			recorrer = recorrer->sig;
		}
		
		if(encontrado == false)
		{
			cout << "\n\t No se encuentra el empleado en la lista." << endl;
		}
	}
	else
	{
		cout << "\n\t No hay empleados en la lista." << endl;
	}
}




