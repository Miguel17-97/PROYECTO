/*
	Name: PROYECTO TIENDA
	Copyright: 
	Author: MIGUEL ANGEL BAÑOL CIFUENTES, DAVID DUQUE VELEZ
	Date: 13/12/20 20:33
	Description: Se desarrolla un proyecto para una tienda básica con operaciones báscias
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

class Nodo
{
	private:
		string producto;
		int precio;
		Nodo *sig;
		Nodo *atras;
		Nodo *primero;
		Nodo *ultimo;
		
	public:
		Nodo();
		void setProducto(string);
		void setPrecio (int);
		void setSig(Nodo *);
		void setAtras(Nodo *);
		void setPrimero(Nodo *);
		void setUltimo(Nodo *);
		string getProducto();
		int getPrecio();
		Nodo *getSig();
		Nodo *getAtras();
		Nodo *getPrimero();
		Nodo *getUltimo();
		void agregarproductos();
		void verPreciosProductos();
		void buscarProducto();
		void actualizarPrecio();
		void eliminarProducto();
	
};


Nodo :: Nodo()
{
	producto = " ";
	precio = 0;
	sig = NULL;
	atras = NULL;
	primero = NULL;
	ultimo = NULL;
}

void Nodo :: setProducto(string producto_n)
{
	producto = producto_n;
}

void Nodo :: setPrecio(int precio_n)
{
	precio = precio_n;
}

void Nodo :: setSig(Nodo *sig_n)
{
	sig = sig_n;
}

void Nodo :: setAtras(Nodo *atras_n)
{
	atras = atras_n;
}

void Nodo :: setPrimero(Nodo *primero_n)
{
	primero = primero_n;
}

void Nodo :: setUltimo(Nodo *ultimo_n)
{
	ultimo = ultimo_n;
}

string Nodo :: getProducto()
{
	return producto;
}

int Nodo :: getPrecio()
{
	return precio;
}

Nodo* Nodo :: getSig()
{
	return sig;
}

Nodo* Nodo :: getAtras()
{
	return atras;
}

Nodo* Nodo :: getPrimero()
{
	return primero;
}

Nodo* Nodo :: getUltimo()
{
	return ultimo;
}

void Nodo :: agregarproductos()
{
	Nodo *nuevo = new Nodo ();
	cout << "\tIngrese el nombre del producto: ";
	fflush(stdin);
	cin >> nuevo->producto;
	fflush(stdin);
	cout << "\n\tIngrese el precio del producto: ";
	fflush(stdin);
	cin >> nuevo->precio;
	fflush(stdin);
	
	if (primero == NULL)
	{
		primero = nuevo;
		ultimo = nuevo;
		primero->sig = primero;
		primero->atras = ultimo;
	}
	else
	{
		ultimo->sig = nuevo;
		nuevo->atras = ultimo;
		nuevo->sig = primero;
		ultimo = nuevo;
		primero->atras = ultimo;
	}
	
	cout << "\tProducto registrado exitosamente\t"<<endl;
	
}

void Nodo :: verPreciosProductos ()
{
	Nodo *recorrer = new Nodo ();
	recorrer = primero;
	
	if (primero != NULL)
	{
		do
		{
			fflush(stdin);
			cout << "\n\t   " << recorrer->producto << " -----> " << recorrer->precio<<"$";
			fflush(stdin);
			recorrer = recorrer->sig;
			
		}while (recorrer != primero);
	}
	else
	{
		cout << "No hay productos en la tienda."<<endl;
	}
	
}

void Nodo :: buscarProducto()
{
	Nodo *recorrer = new Nodo ();
	recorrer = primero;
	bool encontrado = false;
	string producto_bus = " ";
	
	cout << "\n\t Ingrese el nombre del producto a buscar: ";
	fflush(stdin);
	cin >> producto_bus;
	fflush(stdin);
	
	if (primero != NULL)
	{
		do
		{
			if (recorrer->producto == producto_bus)
			{
				fflush(stdin);
				cout << "\n\t Producto encontrado:" << endl << "\t   " << producto_bus << " -----> " << recorrer->precio<<"$";
				fflush(stdin);
				encontrado = true;
			}
			recorrer = recorrer->sig;
			
		}while (recorrer != primero && encontrado != true);
		
		if (!encontrado)
		{
			cout << "\n\t Producto no encontrado." << endl;
		}
	}
	else
	{
		cout << "\n\t No hay productos en la tienda."<<endl;
	}
}

void Nodo :: actualizarPrecio()
{
	Nodo *recorrer = new Nodo ();
	recorrer = primero;
	bool encontrado = false;
	string producto_bus = " ";
	
	cout << "\n\t" << "Ingrese el nombre del producto a buscar para actualizar su precio: ";
	fflush(stdin);
	cin >> producto_bus;
	fflush(stdin);
	
	if (primero != NULL)
	{
		do
		{
			if (recorrer->producto == producto_bus)
			{
				encontrado = true;
				fflush(stdin);
				cout << "\n\t Producto encontrado:" << endl << "\t   " << producto_bus << " -----> " << recorrer->precio <<"$";
				cout << "\n\t Ingrese el nuevo precio del producto: ";
				cin >> recorrer->precio;
				cout << "\n\t Precio actualizado." << endl;
				fflush(stdin);
			}
			recorrer = recorrer->sig;
			
		}while (recorrer != primero && encontrado != true);
		
		if (!encontrado)
		{
			cout << "\n\t Producto no encontrado." << endl;
		}
	}
	else
	{
		cout << "\n\t No hay productos en la tienda."<<endl;
	}
}

void Nodo :: eliminarProducto()
{
	Nodo *recorrer = new Nodo();
	Nodo *anterior = new Nodo(); 
	recorrer = primero;
	anterior = NULL;
	bool encontrado = false;
	string producto_bus = " ";
	
	cout << "\n\t Ingrese el nombre del producto a buscar para eliminar: ";
	fflush(stdin);
	cin >> producto_bus;
	fflush(stdin);
	
	if (primero != NULL)
	{
		do
		{
			if (recorrer->producto == producto_bus)
			{
				fflush(stdin);
				cout << "\n\t Producto encontrado:" << endl << "\t   " << producto_bus << " -----> " << recorrer->precio<<"$";
				fflush(stdin);
				
				if(recorrer == primero)
				{
					primero = primero->sig;
					primero->atras = ultimo;
					ultimo->sig = primero;
					
				}else if (recorrer == ultimo)
				{
					ultimo = anterior;
					ultimo->sig = primero;
					primero->atras = ultimo;
					
				}else
				{
					anterior->sig = recorrer->sig;
					recorrer->sig->atras = anterior;
				}
				
				cout << "\n\t Producto eliminado." << endl;
				encontrado = true;
			}
			
			anterior = recorrer;
			recorrer = recorrer->sig;
			
		}while (recorrer != primero && encontrado != true);
		
		if (!encontrado)
		{
			cout << "\n\t Producto no encontrado." << endl;
		}
	}
	else
	{
		cout << "\n\t No hay productos en la tienda."<<endl;
	}
}
/*
int reavent(string produc[100], int num, float precio[100])
{
	short i, ven;
	float total;
	string opc;
	bool control = true;

	for(i=0; i<num; i++)
	{
		cout <<"\t" << "(" << i+1 << ")" << produc[i] << endl;
	}
	total = 0;
	while(control==true)
	{
		cout << "\tSeleccione el producto a vender: "; cin >> ven;
		total = total + precio[i-1];
		cout << "\tOtro producto por vender? (si/no): "; cin >> opc;
		if(opc=="si")
		{
			control = true;
		}
		else
		{
			control = false;
		}
	}
	
	system("cls");
	cout << "\a";
	cout << "\tEl total a pagar es de: " << total;
}

bool realinv(string produc[100], float precio[100], int num)
{
	short i;
	cout << "\tRealizando inventario, espere un momento";
	for(i=0; i<5; i++)
	{
		cout << ".";
		sleep(1);
	}
	system("cls");
	
	for(i=0; i<num; i++)
	{
		cout << "(" << i+1 << ")" << produc[i] << " con precio de: " << precio[i] << endl;
		sleep(1);
	}
	return true;
}

*/


