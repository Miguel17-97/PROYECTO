/*
	Name: PROYECTO TIENDA
	Copyright: 
	Author: MIGUEL ANGEL BAÑOL CIFUENTES, DAVID DUQUE VELEZ
	Date: 13/12/20 20:33
	Description: Se desarrolla un proyecto para una tienda básica con operaciones báscias
*/

#include <iostream>
#include <stdlib.h>
#include <locale.h>
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
		float vueltoTotal;
		int productosVendidos;
		float gananciasTot;
		
	public:
		Nodo();
		void agregarproductos();
		void verPreciosProductos();
		void buscarProducto();
		void actualizarPrecio();
		void eliminarProducto();
		void realizarVenta();
		void realizarInventario();
		void setvueltoTotal(float);
		void setproductosVendidos(int);
		void setgananciasTot(float);
		float getvueltoTotal();
		int getproductosVendidos();
		float getgananciasTot();
};


Nodo :: Nodo()
{
	producto = " ";
	precio = 0;
	sig = NULL;
	atras = NULL;
	primero = NULL;
	ultimo = NULL;
	vueltoTotal = 0;
	productosVendidos = 0;
	gananciasTot = 0;
}

void Nodo :: setvueltoTotal( float vuelto_total)
{
	vueltoTotal = vuelto_total;
}

void Nodo :: setproductosVendidos(int productos_vendidos)
{
	productosVendidos = productos_vendidos;
}

void Nodo :: setgananciasTot(float ganancias_tot)
{
	gananciasTot = ganancias_tot;
}

float Nodo :: getvueltoTotal()
{
	return vueltoTotal;
}

int Nodo :: getproductosVendidos()
{
	return productosVendidos;
}

float Nodo :: getgananciasTot()
{
	return gananciasTot;
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

void Nodo :: realizarVenta()
{
	Nodo *recorrer = new Nodo ();
	recorrer = primero;
	bool encontrado = false;
	string producto_vent;
	float billete, vuelto;
	int i;
	
	cout << "\n\tBienvenido, ingrese el producto a comprar: ";
	cin >> producto_vent;
	
	if (primero != NULL)
	{
		do
		{
			if (recorrer->producto == producto_vent)
			{
				fflush(stdin);
				cout << "\n\t Ha seleccionado el producto " << producto_vent << " que vale " << recorrer->precio<<"$";
				fflush(stdin);
				encontrado = true;
				cout << "\n\t Por favor, ingrese la denominacion de su billete: ";
				cin >> billete; 
				if(billete < recorrer->precio)
				{
					cout << "\n\t¡Hey! no te alcanza, vuelva pronto ";
				}
				else
				{
					vuelto = billete - recorrer->precio;
					cout << "\n\t Su devuelta es de " << vuelto << ", vuelva pronto!";
					vueltoTotal = vueltoTotal + vuelto;
					setvueltoTotal(vueltoTotal);
					productosVendidos = productosVendidos + 1;
					setproductosVendidos(productosVendidos);
					gananciasTot = gananciasTot + recorrer->precio;
					setgananciasTot(gananciasTot);
				}
			}
			recorrer = recorrer->sig;
			
		}while (recorrer != primero && encontrado != true);
		
		if (!encontrado)
		{
			cout << "\n\t No hay existencias en el momento, vuelva pronto" << endl;
		}
	}
	else
	{
		cout << "\n\t No tenemos surtido por el momento en la tienda."<<endl;
	}
	
}

void Nodo :: realizarInventario()
{
	cout << "\n\t El vuelto dado hoy fue de: ";
	getvueltoTotal();
	cout << vueltoTotal;
	cout << "\n\t El numero de productos vendidos fue de: ";
	getproductosVendidos();
	cout << productosVendidos;
	cout << "\n\t Las ganancias totales han sido de: ";
	getgananciasTot();
	cout << gananciasTot;
	//aca finalizan las funciones
}



